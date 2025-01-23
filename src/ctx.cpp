#include <algorithm>
#include <tsugou/commands.hpp>
#include <tsugou/ctx.hpp>
#include <tsugou/exception.hpp>

#include <fstream>
#include <iostream>

namespace tsugou {

Ctx::Ctx(const Args &args) : args(args) {
  user_config_path = std::getenv("HOME");
  user_config_path += "/.config/tsugou/";

  if (!fs::exists(user_config_path))
    fs::create_directories(user_config_path);

  project_path = fs::current_path();
  project_path += "/.tsu";
}

Args &Ctx::get_args() { return args; }

void Ctx::execute() {
  auto it = std::find_if(
      tsugou::commands.begin(), tsugou::commands.end(),
      [&](const Command &command) { return args[0] == command.name; });

  THROW_ERROR(it == tsugou::commands.end(),
              "Unknown command '" + args[0] + "'");

  const Command &cmd = *it;

  args.erase(args.begin());

  cmd.exec(*this);
}

} // namespace tsugou