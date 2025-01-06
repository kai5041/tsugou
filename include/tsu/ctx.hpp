#ifndef TSUGOU_CTX_HPP
#define TSUGOU_CTX_HPP

#include <tsu/types/author.hpp>
#include <tsu/types/commit.hpp>

namespace tsugou {

class Ctx {
private:
  std::string project_name;
  std::string project_version;
  std::string author_name;
  std::string current_branch;
  std::map<std::string, std::string> scripts;

  Args args;
  std::string command;

public:
  Ctx(const Args &args);


  bool load_project(std::string path);
};

} // namespace tsugou

#endif