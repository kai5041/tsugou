#include <prm/utils.hpp>

#include <prm/command.hpp>

namespace prm {
int print_help(Commands commands) {
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
} // namespace prm