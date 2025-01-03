#include <filesystem>
#include <fstream>
#include <prm/core.hpp>

#include <unistd.h>

int prm::init(Ctx *ctx) {
  try {
    fs::path cwd = fs::current_path();

    std::string project_name = cwd.filename().string();

    ctx->set_setting("project_name", project_name);
  } catch (const std::exception &e) {
    std::cout << "Unable to get current working directory\n";
    return 1;
  }

  ctx->set_setting("prm_version", PRM_VERSION);

  if (ctx->args.size()) {
    ctx->set_setting("template", ctx->args[0]);
  }

  if (fs::exists(".prm")) {
    std::cout << "PRM project already exists\n";
    return 1;
  }

  if (!fs::create_directories(".prm/commits")) {
    std::cout << "Unable to create .prm/commits directory\n";
    return 1;
  }

  chdir(".prm");

  std::ofstream file("config.json");
  file << ctx->get_setting("").dump(2) << std::endl;
  file.close();
  file.open("history");
  file.close();
  file.open("branches");
  file.close();

  return 0;
}
