#ifndef TSUGOU_UTILS_HPP
#define TSUGOU_UTILS_HPP

#include "tsu/json.hpp"
#include <iostream>

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include <chrono>

#include <filesystem>

#include <tsu/json.hpp>

namespace tsugou {

namespace fs = std::filesystem;

using Args = std::vector<std::string>;
using Dict = std::map<std::string, std::string>;
using json = nlohmann::ordered_json;

inline std::uint64_t get_unix_time_ms() {
  auto now = std::chrono::system_clock::now();
  auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
      now.time_since_epoch());
  return now_ms.count();
}

} // namespace tsugou

#endif