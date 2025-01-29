#include <tsugou/commands.hpp>

void tsugou::help(Ctx &ctx) {
  std::cout << std::setw(20) << std::left << "Command"
            << std::setw(30) << std::left << "Syntax"
            << std::setw(30) << std::left << "Description"
            << "\n";
  
  // Separator
  std::cout << std::setw(20) << std::left << std::string(20, '-')
            << std::setw(30) << std::left << std::string(30, '-')
            << std::setw(30) << std::left << std::string(30, '-') << "\n";

  for (const auto &command : tsugou::commands) {
    std::cout << std::setw(20) << std::left << command.name
              << std::setw(30) << std::left << command.syntax
              << std::setw(30) << std::left << command.description << "\n";
  }
}