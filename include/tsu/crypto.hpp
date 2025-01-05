#ifndef TSUGOU_CRYPTO_HPP
#define TSUGOU_CRYPTO_HPP

#include <iomanip>
#include <openssl/evp.h>
#include <sstream>
#include <stdexcept>
#include <string>

namespace tsugou::crypto {

inline std::string sha256(const std::string &input) {
  EVP_MD_CTX *ctx = EVP_MD_CTX_new();
  if (ctx == nullptr) {
    throw std::runtime_error("Failed to create EVP_MD_CTX");
  }

  if (EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr) != 1) {
    EVP_MD_CTX_free(ctx);
    throw std::runtime_error("Failed to initialize SHA256 context");
  }

  if (EVP_DigestUpdate(ctx, input.c_str(), input.length()) != 1) {
    EVP_MD_CTX_free(ctx);
    throw std::runtime_error("Failed to update SHA256 hash");
  }

  unsigned char hash[EVP_MAX_MD_SIZE];
  unsigned int hash_len;
  if (EVP_DigestFinal_ex(ctx, hash, &hash_len) != 1) {
    EVP_MD_CTX_free(ctx);
    throw std::runtime_error("Failed to finalize SHA256 hash");
  }

  EVP_MD_CTX_free(ctx);

  std::stringstream ss;
  for (unsigned int i = 0; i < hash_len; ++i) {
    ss << std::setw(2) << std::setfill('0') << std::hex << (int)hash[i];
  }

  return ss.str();
}

} // namespace tsugou::crypto

#endif