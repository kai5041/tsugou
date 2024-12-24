#include <prm/utils.hpp>

struct Command {
  std::string name;
  std::string description;
  std::string help;
};

using Commands = std::vector<Command>;
Commands commands = {
    {"help", "Prints this help", "prm help"},
    {"version", "Prints the version", "prm version"},
    {"run", "Runs the program", "prm run"},
};

int print_help(Commands &commands) {
  int longest_name = 0;
  int longest_description = 0;
  int longest_help = 0;
  for (auto &command : commands) {
    if (command.name.size() > longest_name) {
      longest_name = command.name.size();
    }
    if (command.description.size() > longest_description) {
      longest_description = command.description.size();
    }
    if (command.help.size() > longest_help) {
      longest_help = command.help.size();
    }
  }
  longest_name += 2;
  longest_description += 2;
  longest_help += 2;

  cout << "Command" << std::string(longest_name - 7, ' ') << "Description\n";

  for (auto &command : commands) {
    cout << command.name << std::string(longest_name - command.name.size(), ' ')
         << command.description << "\n";
  }

  return 0;
}

int main(int argc, char **argv) {
  print_help(commands);

  return 0;
}