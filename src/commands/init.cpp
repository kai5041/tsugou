#include <fstream>
#include <unistd.h>

#include <tsugou/commands.hpp>

void tsugou::init_project(Ctx &ctx) {
  THROW_ERROR(ctx.check_project_exists(), "Tsu project already exists")
  fs::create_directory(ctx.get_project_path());
  chdir(ctx.get_project_path().c_str()); // Move to .tsu

  ctx.get_config() = json::object();

  std::ofstream f("config.json");
  f << ctx.get_config().dump(2);
  f.close();

  f.open("history");
  f.close();
}
