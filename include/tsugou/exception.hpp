#ifndef TSUGOU_EXCEPTION_HPP
#define TSUGOU_EXCEPTION_HPP

#include <string>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#define THROW_ERROR(condition, msg)                                            \
  if (condition) {                                                             \
    tsugou::throw_error(msg);                                                  \
  }

#define THROW_WARNING(condition, msg)                                          \
  if (condition) {                                                             \
    tsugou::throw_error(msg);                                                  \
  }

namespace tsugou {

void throw_error(const std::string &msg);
void throw_warning(const std::string &msg);

} // namespace tsugou

#endif