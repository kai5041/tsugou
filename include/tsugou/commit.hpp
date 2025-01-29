#ifndef TSUGOU_COMMIT_HPP
#define TSUGOU_COMMIT_HPP

#include <tsugou/utils.hpp>

namespace tsugou {

struct Commit {
  std::string hash;
  std::uint64_t timestamp;
  std::string message;
};

} // namespace tsugou

#endif