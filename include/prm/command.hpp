#ifndef PRM_FUNCTION_HPP
#define PRM_FUNCTION_HPP

#include <functional>
#include <string>

namespace prm {

class Ctx;

struct Command {
  std::string name;
  std::function<int(Ctx &)> exec;
};

} // namespace prm

#endif