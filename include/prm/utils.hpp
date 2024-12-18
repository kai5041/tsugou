#ifndef PRM_UTILS_HPP
#define PRM_UTILS_HPP

#include <cstdlib>
#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

namespace prm {

std::string sha256_file(const std::string &path);

inline void set_error_color() {
#ifdef _WIN32
  SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE),
                          FOREGROUND_RED | FOREGROUND_INTENSITY);
#else
  std::cout << "\033[1;31m"; // Bold Red
#endif
}

inline void set_warning_color() {
#ifdef _WIN32
  SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE),
                          FOREGROUND_YELLOW | FOREGROUND_INTENSITY);
#else
  std::cout << "\033[1;33m";
#endif
}

inline void reset_color() {
#ifdef _WIN32
  SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE),
                          FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#else
  std::cout << "\033[0m";
#endif
}

inline void throw_error(const std::string &message) {
  std::cerr << "[";

  set_error_color();

  std::cerr << "ERROR";

  reset_color();

  std::cerr << "] " << message << "\n";

  exit(1);
}

inline void throw_note(const std::string &message) {
  std::cerr << "[";

  set_warning_color();

  std::cout << "NOTE";

  reset_color();

  std::cerr << "] " << message << "\n";
}

} // namespace prm

#endif
