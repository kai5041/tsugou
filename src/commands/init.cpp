#include <fstream>
#include <tsugou/commands.hpp>

void tsugou::init_project(Ctx &ctx) {
  THROW_ERROR(ctx.check_project_exists(), "Tsu project already exists")
  fs::create_directory(ctx.get_project_path());

  std::ofstream f(ctx.get_project_path() + "/config.json");
  f << ctx.get_config().dump(2);
}
