#ifndef TSUGOU_AUTHOR_HPP
#define TSUGOU_AUTHOR_HPP

#include <tsu/utils.hpp>

namespace tsugou {

class Author {
private:
  std::string username;
  Dict contacts;

public:
  Author(std::string username = "", Dict contacts = Dict());

  void set_contact(std::string platform, std::string value);

  std::string get_username();
  Dict get_contacts();
  std::string get_contact(std::string platform);

  std::string to_string();
};

} // namespace tsugou

#endif