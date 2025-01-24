#include "tsugou/sha2_256.hpp"
#include <iostream>

#include <tsugou/ctx.hpp>
#include <tsugou/exception.hpp>
#include <tsugou/utils.hpp>

int main(int argc, char **argv) {

  tsugou::Args args(argv + 1, argv + argc);

  std::cout << tsugou::sha2_256_file("run") << std::endl;

  THROW_ERROR(args.empty(), "No arguments provided. Check `tsu help` for more")

  tsugou::Ctx ctx(args);

  ctx.execute();

  return 0;
}
