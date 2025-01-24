#ifndef TSUGOU_USER_HPP
#define TSUGOU_USER_HPP

#include <map>
#include <string>

#include <tsugou/ctx.hpp>

namespace tsugou {

class User {
private:
  std::string uuid;
  
public:
  User(const std::string &uuid);
};

} // namespace tsugou

#endif