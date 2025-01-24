#ifndef TSUGOU_USER_HPP
#define TSUGOU_USER_HPP

#include <map>
#include <string>

namespace tsugou {

using Contacts = std::map<std::string, std::string>;

class User {
private:
  std::string uuid;
  
public:
  User(const std::string &uuid);
};

} // namespace tsugou

#endif