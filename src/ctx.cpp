#include <prm/ctx.hpp>

namespace prm {

Ctx::Ctx(Args &&args) { this->args = args; }

void Ctx::set_setting(std::string key, std::string value) {
  settings[key] = value;
}

json Ctx::get_setting(std::string key) {
  if (key == "")
    return this->settings;
  return settings[key];
}

} // namespace prm