#include <prm/utils.hpp>

struct Command {
  std::string name;
  std::string description;
  std::string syntax;
};

using Commands = std::vector<Command>;
Commands commands = {
    {"help", "Prints this message", "prm help"},
    {"version", "Prints current prm version", "prm version"},
    {"run", "Run the project", "prm run <project_name>"},
    {"init", "Initialize a new project", "prm init"},
    {"create", "Create a new prm project"}
};

int print_help(Commands &commands) {
  int longest_name = 0, longest_description = 0, longest_syntax = 0;
  for (auto &command : commands) {
    longest_name = std::max(longest_name, (int)command.name.size());
    longest_description =
        std::max(longest_description, (int)command.description.size());
    longest_syntax = std::max(longest_syntax, (int)command.syntax.size());
  }
  longest_name += 2;
  longest_description += 2;
  longest_syntax += 2;

  cout << "Command" << std::string(longest_name - 7, ' ') << "Description"
       << std::string(longest_description - 11, ' ') << "Syntax\n";
  for (auto &command : commands) {
    cout << command.name << std::string(longest_name - command.name.size(), ' ')
         << command.description
         << std::string(longest_description - command.description.size(), ' ')
         << command.syntax << "\n";
  }
  return 0;
}

int main(int argc, char **argv) {
  print_help(commands);

  return 0;
}