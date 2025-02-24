#ifndef TSUGOU_CTX_HPP
#define TSUGOU_CTX_HPP

#include <tsugou/utils.hpp>

#include <tsugou/json.hpp>

namespace tsugou {

using json = nlohmann::ordered_json;

class Ctx {
private:
  std::string user_config_path;
  std::string project_path;
  json config;

  Args args;

public:
  Ctx(const Args &args);

  std::string &get_user_config_path();
  std::string &get_project_path();
  Args &get_args();
  
  json &get_config();
  void set_config_field(const std::string &key, const json &value);

  bool check_project_exists();
  void apply_changes();

  void execute();
};

} // namespace tsugou

#endif