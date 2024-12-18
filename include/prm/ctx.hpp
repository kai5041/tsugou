#ifndef PRM_CTX_HPP
#define PRM_CTX_HPP

#include <string>
#include <vector>

namespace prm {

typedef std::vector<std::string> Args;

class Ctx {
private:
  Args args;

public:
  Ctx(const Args &args);
  inline Args &get_args() { return args; }
};

} // namespace prm

#endif