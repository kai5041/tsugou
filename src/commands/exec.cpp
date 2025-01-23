#include "tsugou/exception.hpp"
#include <cstdlib>
#include <tsugou/commands.hpp>

void tsugou::execute_script(Ctx &ctx) {
  THROW_ERROR(ctx.get_args().size() == 0, "Missing script name")

  std::string script_name = ctx.get_args()[0];
  std::string command = "";

  for (const auto &script : ctx.get_config()["scripts"].items()) {
    if (script.key() == script_name) {
      command = script.value();
      break;
    }
  }

  THROW_ERROR(command == "", "Script '" + script_name + "' not found")

  std::exit(system(command.c_str()));
}
