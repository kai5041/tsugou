#include <iostream>

#include <prm/core.hpp>

using namespace prm;

int main(int argc, char **argv) {

  if (argc < 2)
    prm::throw_error("No arguments provided");

  std::string cmd = argv[1];
  Args args(argv + 2, argv + argc);
  prm::Ctx ctx(args);

  for (const auto &command : prm::functions) {
    if (command.name == cmd) {
      return command.exec(ctx);
    }
  }

  

  prm::throw_error("Command '" + cmd + "' not found");
}
