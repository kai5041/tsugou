#ifndef PRM_COMMAND_HPP
#define PRM_COMMAND_HPP

#include <functional>
#include <string>

#include <prm/utils.hpp>
#include <prm/ctx.hpp>

namespace prm {

struct Command {
  std::string name;
  std::string description;
  std::string syntax;
  std::function<int(Ctx *)> func;
};

using Commands = std::vector<Command>;

int print_help(Commands &commands);

} // namespace prm
#endif