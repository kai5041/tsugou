#include <tsu/core.hpp>

#include <fstream>

using namespace tsugou;

int main(int argc, char **argv) {

  if (argc < 2) {
    std::cerr << "Usage: tsugou <command>" << std::endl;
    return 1;
  }

  Args args = Args(argv + 1, argv + argc);

  Ctx ctx(args);

  return ctx.execute_command();
}
