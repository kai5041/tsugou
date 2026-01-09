#include <iostream>

#include <tsugou/Dispatcher.hpp>

int main(int argc, char **argv) {
  auto args = tsugou::Vec<std::string>({argv, argv + argc});

  if (args.size() == 1) {
    std::cerr << "Please provide a command." << std::endl;
    return 1;
  }

  args.erase(args.begin());

  return tsugou::Dispatcher(std::move(args)).dispatch();
}
