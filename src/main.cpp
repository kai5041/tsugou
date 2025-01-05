#include <tsu/core.hpp>

using namespace tsugou;

int main(int argc, char **argv) {
  Author author("kai", {{"github", "kai5041"}});

  Commit x(tsugou::crypto::sha256("test"), author.get_username(), 0,
           "test msg");

  std::cout << x.to_string() << std::endl;

  std::cout << author.to_string() << std::endl;

  return 0;
}