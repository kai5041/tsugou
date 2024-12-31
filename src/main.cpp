#include "prm/command.hpp"
#include <prm/core.hpp>

using namespace prm;

int main(int argc, char **argv) {

  if (argc < 2) {
    version();
    std::cout << "Enter 'prm help' for further instructions\n";
    return 0;
  }

  std::string command = argv[1];
  Command *cmd = nullptr;

  for (Command &c : prm::commands) {
    if (c.name == command) {
      cmd = &c;
      break;
    }
  }

  Ctx ctx(Args(argv + 2, argv + argc));

  if (!cmd) {
    std::cout << "Command '" << command << "' not found\n";
    return 0;
  }

  return cmd->func(&ctx);
}
