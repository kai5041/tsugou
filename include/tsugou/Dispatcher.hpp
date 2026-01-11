#pragma once

#include <functional>

#include <tsugou/defs.hpp>

namespace tsugou {

  class Dispatcher;

  struct Command {
    std::string name;
    std::string help;
    std::function<u32(Dispatcher&)> func;
  };

  u32 build_cpp(Dispatcher&);

  class Dispatcher {
  private:
    Vec<std::string> args;
    Map<std::string, Command> commands;

  public:
    Dispatcher(Vec<std::string> args);
    inline auto& get_args() { return args; }

    u32 dispatch();
  };

  inline void print_err_if(bool condition, String msg) {
    if (!condition) return;

    std::cout << "[" << colors::RED << "ERROR" << colors::RESET << "] tsu: " + msg + "\n";
    std::exit(1);
  }

  inline void print_info_if(bool condition, String msg) {
    if (!condition) return;

    std::cout << "[" << colors::CYAN << "INFO" << colors::RESET << "] tsu: " + msg << "\n";
  }

} // namespace tsugou
