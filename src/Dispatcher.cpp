#include <iostream>
#include <tsugou/Dispatcher.hpp>

namespace tsugou {

Dispatcher::Dispatcher(Vec<std::string> args) : args(std::move(args)) {

  commands["version"] = {
      "version",
      "Print version",
      [](Dispatcher & /*dispatcher*/) {
        std::cout << "Tsugou 0.0.0\n";
        std::cout << "Repository: https://github.com/kai5041/tsugou"
                  << std::endl;
        return 0;
      },
  };

  commands["help"] = {"help", "Print help", [](Dispatcher &dispatcher) {
                        std::cout << "Available commands:" << std::endl;
                        for (const auto &command : dispatcher.commands) {
                          std::cout << "  " << command.first << ": "
                                    << command.second.help << std::endl;
                        }
                        return 0;
                      }};

  commands["build-cpp"] = {"help", "Build C++17 project", build_cpp};
}

u32 Dispatcher::dispatch() {
  auto it = commands.find(args[0]);

  if (it == commands.end()) {
    std::cerr << "Command not found: " << args[0] << std::endl;
    return 1;
  }

  args.erase(args.begin());

  auto &cmd = it->second;

  auto result = cmd.func(*this);

  return result;
}

} // namespace tsugou
