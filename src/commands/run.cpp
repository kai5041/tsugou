#include <prm/core.hpp>

#include <fstream>

int prm::run(Ctx *ctx) {

  if (!fs::exists(".prm")) {
    std::cout << "Not a PRM project\n";
    return 1;
  }

  if (!fs::exists(".prm/config.json")) {
    std::cout << "File .prm/config.json not found\n";
    return 1;
  }

  {
    std::ifstream f(".prm/config.json");
    ctx->settings = json::parse(f);
  }

  std::string template_name = ctx->get_setting("template").get<std::string>();
  std::string cmd = "";

  if (template_name == "cmake") {
    cmd = "mkdir -p build && cd build && cmake .. && make && ./" +
          ctx->get_setting("project_name").get<std::string>() + " ";
  } else {
    std::cout << "Template '" << template_name << "' not found\n";
    return 1;
  }

  for (const auto &arg : ctx->args) {
    cmd += arg + " ";
  }

  int status = std::system(cmd.c_str());

  return status;
}