#ifndef TSUGOU_USER_HPP
#define TSUGOU_USER_HPP

#include <map>
#include <string>

namespace tsugou {

using Contacts = std::map<std::string, std::string>;

class User {
private:
  std::string username;
  std::string timezone;
  Contacts contacts;

public:
};

} // namespace tsugou

#endif