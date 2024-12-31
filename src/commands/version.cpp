#include <prm/core.hpp>

int prm::version(Ctx *ctx [[maybe_unused]]) {
  cout << "PRM version " << PRM_VERSION << "\n";
  cout << "Github: https://github.com/kai5041/prm\n";
  return 0;
}
