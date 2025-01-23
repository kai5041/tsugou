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

  Args &get_args();

  void execute();
};

} // namespace tsugou

#endif