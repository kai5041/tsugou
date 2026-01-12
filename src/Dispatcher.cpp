#include <iostream>
#include <tsugou/Dispatcher.hpp>

namespace tsugou {

  Dispatcher::Dispatcher(Vec<std::string> args) : args(std::move(args)) {

    commands["version"] = {
        "version",
        "Print version",
        [](Dispatcher& /*dispatcher*/) {
          std::cout << "Tsugou 0.0.1 - \"Kai Burned Out Edition\"\n";
          std::cout << "Repository: https://github.com/kai5041/tsugou"
                    << std::endl;
          return 0;
        },
    };

    commands["help"] = { "help", "Print help", [](Dispatcher& dispatcher) {
                          std::cout << "Available commands:" << std::endl;
                          for (const auto& command : dispatcher.commands) {
                            std::cout << "  " << command.first << ": "
                                      << command.second.help << std::endl;
                          }
                          return 0;
                        } };

    commands["build-cpp"] = { "help", "Build C++ project with flags <CXX> <SRC_FOLDER> <OUTPUT_FILENAME> [CXX_FLAGS] [LD_FLAGS]", build_cpp };
  }

  u32 Dispatcher::dispatch() {
    auto it = commands.find(args[0]);

    print_err_if(it == commands.end(), "Command '" + args[0] + "' not found");

    args.erase(args.begin());

    auto& cmd = it->second;

    auto result = cmd.func(*this);

    return result;
  }

} // namespace tsugou
