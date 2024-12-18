#include <prm/utils.hpp>

#include <fstream>
#include <iomanip>
#include <sstream>

#include <openssl/evp.h>

namespace prm {

std::string sha256_file(const std::string &path) {
  std::ifstream file(path, std::ios::binary);
  if (!file) {
    std::cerr << "Error opening file!" << std::endl;
    return "";
  }

  EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
  if (!mdctx) {
    std::cerr << "Error creating context!" << std::endl;
    return "";
  }

  // Initialize SHA-256 hash algorithm
  if (EVP_DigestInit_ex(mdctx, EVP_sha256(), nullptr) != 1) {
    std::cerr << "Error initializing digest!" << std::endl;
    EVP_MD_CTX_free(mdctx);
    return "";
  }

  const size_t bufferSize = 8192;
  char buffer[bufferSize];

  // Read the file in chunks and update the hash
  while (file.read(buffer, bufferSize)) {
    if (EVP_DigestUpdate(mdctx, buffer, file.gcount()) != 1) {
      std::cerr << "Error updating digest!" << std::endl;
      EVP_MD_CTX_free(mdctx);
      return "";
    }
  }

  // Process the last part of the file if it's not a full buffer
  if (file.gcount() > 0) {
    if (EVP_DigestUpdate(mdctx, buffer, file.gcount()) != 1) {
      std::cerr << "Error updating digest!" << std::endl;
      EVP_MD_CTX_free(mdctx);
      return "";
    }
  }

  unsigned char hash[EVP_MAX_MD_SIZE];
  unsigned int hashLength = 0;

  // Finalize the hash computation
  if (EVP_DigestFinal_ex(mdctx, hash, &hashLength) != 1) {
    std::cerr << "Error finalizing digest!" << std::endl;
    EVP_MD_CTX_free(mdctx);
    return "";
  }

  EVP_MD_CTX_free(mdctx);

  // Convert the hash to a hex string
  std::ostringstream hexStream;
  for (unsigned int i = 0; i < hashLength; ++i) {
    hexStream << std::setw(2) << std::setfill('0') << std::hex << (int)hash[i];
  }

  return hexStream.str();
}

} // namespace prm