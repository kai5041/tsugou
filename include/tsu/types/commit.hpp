#ifndef TSUGOU_COMMIT_HPP
#define TSUGOU_COMMIT_HPP

#include <cstdint>
#include <string>

namespace tsugou {

class Commit {
private:
  std::string hash;
  std::string author;
  std::uint64_t timestamp_ms;
  std::string message;

public:
  Commit(std::string hash, std::string author, std::uint64_t timestamp_ms,
         std::string message);

  std::string get_hash() const;
  std::string get_author() const;
  std::uint64_t get_timestamp_ms() const;
  std::string get_message() const;

  std::string to_string();
};

} // namespace tsugou

#endif