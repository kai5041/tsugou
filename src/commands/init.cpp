#include <tsugou/commands.hpp>

void tsugou::init_project(Ctx &ctx) {
  std::cout << ctx.get_args().size() << std::endl;
  std::cout << "Initializing project" << std::endl;
}
