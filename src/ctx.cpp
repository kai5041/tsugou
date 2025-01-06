#include <tsu/ctx.hpp>

#include <tsu/json.hpp>

#include <fstream>

namespace tsugou {

Ctx::Ctx(const Args &args) {
  
  command = args[0];
}


bool Ctx::load_project(std::string path) { return true; }

} // namespace tsugou