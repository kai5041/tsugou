#include <iostream>

#include <tsugou/ctx.hpp>
#include <tsugou/exception.hpp>
#include <tsugou/utils.hpp>
#include <tsugou/version.hpp>

int main(int argc, char **argv) {

  tsugou::Args args(argv + 1, argv + argc);

  if (args.empty()) {
    std::cout << "tsugou version " << TSUGOU_VERSION << std::endl;
    std::cout << "Enter `tsu help` for more" << std::endl;
    return 0;
  }

  tsugou::Ctx(args).execute();

  return 0;
}
