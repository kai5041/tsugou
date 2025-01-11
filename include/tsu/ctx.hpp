#ifndef TSUGOU_CTX_HPP
#define TSUGOU_CTX_HPP

#include <tsu/command.hpp>
#include <tsu/types/author.hpp>
#include <tsu/types/commit.hpp>

namespace tsugou {

class Ctx {
private:
  std::vector<Command> commands;
  Args args;
  Command *command;

  std::string project_name;
  std::string project_version;
  std::string author_name;
  std::string current_branch;
  std::map<std::string, std::string> scripts;

public:
  Ctx(const Args &args);

  void init_commands();

  int execute_command();

  bool load_project();

  int init_project();
  int exec_script();

};

} // namespace tsugou

#endif