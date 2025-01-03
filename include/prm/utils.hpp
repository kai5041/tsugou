#ifndef PRM_UTILS_HPP
#define PRM_UTILS_HPP

#include <filesystem>
#include <iostream>
#include <vector>

#include <prm/json.hpp>

using std::cout;

namespace fs = std::filesystem;

namespace prm {

using Args = std::vector<std::string>;
using json = nlohmann::ordered_json;

} // namespace prm

#endif