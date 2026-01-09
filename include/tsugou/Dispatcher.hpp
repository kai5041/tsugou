#pragma once

#include <functional>

#include <tsugou/defs.hpp>

namespace tsugou {

class Dispatcher;

struct Command {
  std::string name;
  std::string help;
  std::function<u32(Dispatcher &)> func;
};

u32 build_cpp(Dispatcher &);

class Dispatcher {
private:
  Vec<std::string> args;
  Map<std::string, Command> commands;

public:
  Dispatcher(Vec<std::string> args);
  inline auto &get_args() { return args; }

  u32 dispatch();
};

} // namespace tsugou
