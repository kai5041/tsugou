#ifndef TSU_COMMAND_HPP
#define TSU_COMMAND_HPP

#include <string>
#include <functional>

namespace tsugou {

struct Command {
  std::string name;
  std::function<int()> exec;
  bool requires_init = 0;
};

} // namespace tsugou

#endif