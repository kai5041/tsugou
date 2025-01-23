#ifndef TSUGOU_COMMAND_HPP
#define TSUGOU_COMMAND_HPP

#include <functional>
#include <vector>

#include <tsugou/ctx.hpp>

namespace tsugou {

struct Command {
  std::string name;
  std::string description;
  std::string syntax;
  std::function<void(Ctx &)> exec;
  bool requires_project = false;
};

using Commands = std::vector<Command>;

} // namespace tsugou

#endif