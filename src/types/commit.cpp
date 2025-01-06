#include <tsu/types/commit.hpp>

namespace tsugou {

Commit::Commit(const std::string &hash, const std::string &branch,
                const std::string &author, std::uint64_t timestamp_ms,
                const std::string &message) {
  this->hash = hash;
  this->branch = branch;
  this->author = author;
  this->timestamp_ms = timestamp_ms;
  this->message = message;
}

std::string Commit::get_hash() const { return hash; }
std::string Commit::get_branch() const { return branch; }
std::string Commit::get_author() const { return author; }
std::uint64_t Commit::get_timestamp_ms() const { return timestamp_ms; }
std::string Commit::get_message() const { return message; }

std::string Commit::to_string() const {
  std::string str = "";
  str += hash + " ";
  str += branch + " ";
  str += author + " ";
  str += std::to_string(timestamp_ms) + " ";
  str += message;
  return str;
}

} // namespace tsugou
