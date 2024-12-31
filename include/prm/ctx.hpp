#ifndef PRM_CTX_HPP
#define PRM_CTX_HPP

#include <prm/utils.hpp>

namespace prm {

class Ctx {
private:
  json settings;
  Args args;

public:
  Ctx(Args &&args);
};

} // namespace prm

#endif