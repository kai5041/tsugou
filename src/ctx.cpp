#include <tsu/ctx.hpp>

#include <tsu/json.hpp>

#include <filesystem>
#include <fstream>

namespace tsugou {

Ctx::Ctx(const Args &args) : command(nullptr) {
  this->args = args;

  init_commands();

  for (auto &cmd : commands) {
    if (cmd.name == args[0]) {
      command = &cmd;
      this->args.erase(this->args.begin());
      break;
    }
  }
}

void Ctx::init_commands() {
  commands.push_back({"init", [this]() { return init_project(); }});
  commands.push_back({"exec", [this]() { return exec_script(); }, true});
}

int Ctx::execute_command() {
  if (!command) {
    std::cout << "Error: command not found\n";
    return 1;
  }

  if (command->requires_init) {
    load_project();
  }

  return command->exec();
}

bool Ctx::load_project() {
  if (!fs::exists(".tsu/config.json")) {
    std::cout << "Error: project not found\n";
    return 1;
  }

  json config =
      json::parse(std::ifstream(".tsu/config.json"), nullptr, true, true);

  for (auto &pair :
       config["scripts"].get<std::map<std::string, std::string>>()) {
    scripts[pair.first] = pair.second;
  }

  return 0;
}

int Ctx::init_project() {
  std::cout << "tsugou init\n";
  return 0;
}

int Ctx::exec_script() {
  std::cout << "tsugou exec\n";
  return 0;
}

} // namespace tsugou