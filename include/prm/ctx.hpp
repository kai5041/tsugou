#ifndef PRM_CTX_HPP
#define PRM_CTX_HPP

#include <prm/utils.hpp>

namespace prm {

class Ctx {
public:
  json settings = {{"project_name", ""},
                   {"project_version", ""},
                   {"prm_version", ""},
                   {"template", ""},
                   {"author", ""},
                   {"branch", ""},
                   {"scripts", json::object()},
                   {"ignores", json::array()}};

  Args args;

  Ctx(Args &&args);
  void set_setting(std::string key, std::string value);
  json get_setting(std::string key);
};

} // namespace prm

#endif