#include <iostream>

#include <tsugou/Dispatcher.hpp>

int main(int argc, char** argv) {
  auto args = tsugou::Vec<std::string>({ argv, argv + argc });

  tsugou::print_err_if(args.size() == 1, "Provide a command");

  args.erase(args.begin());

  return tsugou::Dispatcher(std::move(args)).dispatch();
}
