#include <cstdlib>
#include <iostream>

#include <tsugou/exception.hpp>

namespace tsugou {

void throw_error(const std::string &msg) {
  std::cerr << "[" << RED << "ERROR" << RESET << "] " << msg << std::endl;
  std::exit(1);
}

void throw_warning(const std::string &msg) {
  std::cerr << "[" << YELLOW << "WARNING" << RESET << "] " << msg << std::endl;
}

} // namespace tsugou
