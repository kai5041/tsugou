#include <filesystem>
#include <fstream>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#include <PicoSHA2/picosha2.h>
#include <tsugou/Dispatcher.hpp>

namespace tsugou {

namespace fs = std::filesystem;

static std::unordered_map<std::string, std::string>
load_cache(const fs::path &cache_file) {
  std::unordered_map<std::string, std::string> cache;
  std::ifstream in(cache_file);
  if (!in.is_open())
    return cache;

  std::string line;
  while (std::getline(in, line)) {
    std::istringstream iss(line);
    std::string path, hash;
    if (iss >> path >> hash)
      cache[path] = hash;
  }
  return cache;
}

static void
save_cache(const fs::path &cache_file,
           const std::unordered_map<std::string, std::string> &cache) {
  std::ofstream out(cache_file, std::ios::trunc);
  for (const auto &[path, hash] : cache)
    out << path << " " << hash << "\n";
}

u32 build_cpp(Dispatcher &dispatcher) {
  u32 ret = 0;

  auto args = dispatcher.get_args();
  if (args.size() < 3)
    return 1;

  std::string compiler = args[0];
  fs::path folder = args[1];
  fs::path output = args[2];
  std::string cxx_flags = (args.size() > 3) ? args[3] : "";
  std::string ld_flags = (args.size() > 4) ? args[4] : "";

  if (!fs::exists(folder) || !fs::is_directory(folder))
    return 1;

  fs::path build_dir = fs::current_path() / "build";
  fs::create_directories(build_dir);

  fs::path cache_file = build_dir / "cache";
  auto cache = load_cache(cache_file);

  std::vector<fs::path> to_compile;
  std::vector<fs::path> obj_files;
  bool target_exists = fs::exists(build_dir / output.filename());

  for (auto &entry : fs::recursive_directory_iterator(folder)) {
    if (!entry.is_regular_file() || entry.path().extension() != ".cpp")
      continue;

    std::ifstream file(entry.path(), std::ios::binary);
    std::vector<unsigned char> buffer((std::istreambuf_iterator<char>(file)),
                                      {});
    std::vector<unsigned char> hash(picosha2::k_digest_size);
    picosha2::hash256(buffer.begin(), buffer.end(), hash.begin(), hash.end());
    std::string hex_hash =
        picosha2::bytes_to_hex_string(hash.begin(), hash.end());

    std::string rel_path =
        fs::relative(entry.path(), fs::current_path()).string();
    fs::path obj_file = build_dir / (entry.path().stem().string() + ".o");
    obj_files.push_back(obj_file);

    if (cache[rel_path] != hex_hash) {
      to_compile.push_back(entry.path());
      cache[rel_path] = hex_hash;
    }
  }

  if (!to_compile.empty()) {
    unsigned int n_threads = std::thread::hardware_concurrency();
    if (n_threads == 0)
      n_threads = 1;

    std::mutex mtx;
    size_t index = 0;
    auto worker = [&]() {
      while (true) {
        fs::path file;
        fs::path obj_file;
        {
          std::lock_guard<std::mutex> lock(mtx);
          if (index >= to_compile.size())
            return;
          file = to_compile[index];
          obj_file = build_dir / (file.stem().string() + ".o");
          index++;
        }

        std::ostringstream cmd;
        cmd << compiler << " -c ";
        if (!cxx_flags.empty())
          cmd << cxx_flags << " ";
        cmd << file.string() << " -o " << obj_file.string();

        std::cout << cmd.str() << "\n";
        int result = std::system(cmd.str().c_str());
        if (result != 0)
          std::exit(result);
      }
    };

    std::vector<std::thread> threads;
    for (unsigned int i = 0; i < n_threads; ++i)
      threads.emplace_back(worker);
    for (auto &t : threads)
      t.join();
  }

  if (!to_compile.empty() || !target_exists) {
    fs::path target_path = build_dir / output.filename();
    std::ostringstream link_cmd;
    link_cmd << compiler << " ";
    for (auto &obj : obj_files)
      link_cmd << obj.string() << " ";
    if (!ld_flags.empty())
      link_cmd << ld_flags << " ";
    link_cmd << "-o " << target_path.string();

    std::cout << link_cmd.str() << "\n";
    int link_result = std::system(link_cmd.str().c_str());
    if (link_result != 0)
      return link_result;
  }

  save_cache(cache_file, cache);
  return ret;
}

} // namespace tsugou
