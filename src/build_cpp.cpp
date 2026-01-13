#include <filesystem>
#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>

#include <PicoSHA2/picosha2.h>
#include <tsugou/Dispatcher.hpp>

namespace tsugou {

  namespace fs = std::filesystem;

  struct CacheEntry {
    String cmd;
    String hash;
  };

  static String sha256_file_with_cmd(const String& path, const String& cmd) {
    std::ifstream f(path, std::ios::binary);
    std::vector<unsigned char> h1(picosha2::k_digest_size);
    picosha2::hash256(f, h1.begin(), h1.end());

    String hex1;
    picosha2::bytes_to_hex_string(h1.begin(), h1.end(), hex1);

    std::vector<unsigned char> h2(picosha2::k_digest_size);
    picosha2::hash256(cmd.begin(), cmd.end(), h2.begin(), h2.end());

    String hex2;
    picosha2::bytes_to_hex_string(h2.begin(), h2.end(), hex2);

    return hex1 + hex2;
  }

  Vec<String> list_files_recursively(String path, String suffix) {
    Vec<String> files;
    try {
      if (!fs::exists(path)) return files;
      for (auto& entry : fs::recursive_directory_iterator(path)) {
        if (entry.is_regular_file()) {
          String p = entry.path().string();
          if (p.size() >= suffix.size() &&
            p.compare(p.size() - suffix.size(), suffix.size(), suffix) == 0) {
            files.push_back(p);
          }
        }
      }
    }
    catch (...) {}
    return files;
  }

  u32 build_cpp(Dispatcher& dispatcher) {
    auto& args = dispatcher.get_args();

    print_err_if(args.size() == 0, "C++ compiler missing");
    print_err_if(args.size() == 1, "Source directory missing");
    print_err_if(args.size() == 2, "Target file missing");

    String CXX = args[0];
    String SRC = args[1];
    String TARGET = args[2];
    String CXX_FLAGS = args.size() > 3 ? args[3] : "";
    String CXX_LD_FLAGS = args.size() > 4 ? args[4] : "";

    String BUILD_DIR = "build";
    String TSU_DIR = ".tsu";

    fs::create_directories(BUILD_DIR);
    fs::create_directories(TSU_DIR);

    fs::path cache_path = fs::path(TSU_DIR) / "cache";
    std::unordered_map<String, CacheEntry> cache;

    // Load cache
    {
      std::ifstream in(cache_path);
      String line;
      while (std::getline(in, line)) {
        std::istringstream iss(line);
        String file, cmd, hash;
        if (!std::getline(iss, file, '|')) continue;
        if (!std::getline(iss, cmd, '|')) continue;
        if (!std::getline(iss, hash)) continue;

        auto trim = [](String& s) {
          while (!s.empty() && s.front() == ' ') s.erase(0, 1);
          while (!s.empty() && s.back() == ' ') s.pop_back();
          };
        trim(file); trim(cmd); trim(hash);

        cache[file] = { cmd, hash };
      }
    }

    auto files = list_files_recursively(SRC, ".cpp");

    Vec<String> obj_files(files.size());
    for (size_t i = 0; i < files.size(); ++i) {
      fs::path p(files[i]);
      obj_files[i] = BUILD_DIR + "/" + p.stem().string() + ".o";
    }

    std::atomic<size_t> index{ 0 };
    std::atomic<u32> fail{ 0 };
    std::mutex log_mutex;
    std::mutex cache_mutex;

    size_t n = std::thread::hardware_concurrency();
    if (n == 0) n = 1;

    auto start = std::chrono::high_resolution_clock::now(); // start timer

    auto worker = [&]() {
      for (;;) {
        size_t i = index.fetch_add(1);
        if (i >= files.size()) break;

        fs::path src_path = fs::relative(files[i], fs::current_path());
        String src = src_path.string();

        fs::path obj_path = fs::path(BUILD_DIR) / fs::path(files[i]).stem();
        String obj = obj_path.string() + ".o";
        obj_files[i] = obj;

        String cmd = CXX + " -c " + src + " -o " + obj + " " + CXX_FLAGS;
        String hash = sha256_file_with_cmd(src, cmd);

        // Only skip if cache matches AND object exists
        bool skip = false;
        {
          std::lock_guard<std::mutex> lock(cache_mutex);
          auto it = cache.find(src);
          if (it != cache.end() && it->second.cmd == cmd && it->second.hash == hash) {
            if (fs::exists(obj)) skip = true;
          }
          if (!skip) cache[src] = { cmd, hash };
        }

        if (skip) continue;

        {
          std::lock_guard<std::mutex> lock(log_mutex);
          print_info_if(1, cmd);
        }

        if (std::system(cmd.c_str()) != 0) {
          fail++;
        }
      }
      };

    Vec<std::thread> threads;
    for (size_t i = 0; i < n; ++i)
      threads.emplace_back(worker);
    for (auto& t : threads)
      t.join();

    if (fail > 0) return 1;

    // Write cache
    {
      std::ofstream out(cache_path, std::ios::trunc);
      for (auto& [file, entry] : cache) {
        out << file << " | " << entry.cmd << " | " << entry.hash << "\n";
      }
    }

    // Link step
    String link_cmd = CXX + " -o " + BUILD_DIR + "/" + TARGET;
    for (auto& o : obj_files) link_cmd += " " + o;
    link_cmd += " " + CXX_LD_FLAGS;

    {
      std::lock_guard<std::mutex> lock(log_mutex);
      print_info_if(1, link_cmd);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

print_info_if(1, 
    "Elapsed: " + std::to_string(duration.count()) + 
    " us | Energy used: " + 
    std::to_string(15.0 / 0.9 * duration.count() * 1e-6) + " J"
);

    return std::system(link_cmd.c_str());
  }

} // namespace tsugou
