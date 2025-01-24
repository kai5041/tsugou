#ifndef TSUGOU_SHA256_HPP
#define TSUGOU_SHA256_HPP

#include <openssl/evp.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include <tsugou/exception.hpp>

namespace tsugou {

inline std::string sha2_256(const std::string &input) {
  EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
  if (mdctx == nullptr) {
    std::cerr << "Error creating EVP_MD_CTX.\n";
    return "";
  }

  if (1 != EVP_DigestInit_ex(mdctx, EVP_sha256(), nullptr)) {
    std::cerr << "Error initializing SHA-256.\n";
    EVP_MD_CTX_free(mdctx);
    return "";
  }

  if (1 != EVP_DigestUpdate(mdctx, input.c_str(), input.size())) {
    std::cerr << "Error updating SHA-256 hash.\n";
    EVP_MD_CTX_free(mdctx);
    return "";
  }

  unsigned char hash[EVP_MAX_MD_SIZE];
  unsigned int hash_len;
  if (1 != EVP_DigestFinal_ex(mdctx, hash, &hash_len)) {
    std::cerr << "Error finalizing SHA-256 hash.\n";
    EVP_MD_CTX_free(mdctx);
    return "";
  }

  EVP_MD_CTX_free(mdctx);

  std::stringstream hex_stream;
  for (unsigned int i = 0; i < hash_len; ++i) {
    hex_stream << std::setw(2) << std::setfill('0') << std::hex << (int)hash[i];
  }

  return hex_stream.str();
}

inline std::string sha2_256_file(const std::string &filename) {
  unsigned char hash[EVP_MAX_MD_SIZE];
  unsigned int hash_len = 0;

  // Open the file
  std::ifstream file(filename, std::ios::binary);
  if (!file) {
    THROW_ERROR(1, "Error opening file '" + filename + "'");
  }

  std::cout << "File '" << filename << "' opened successfully."
            << std::endl; // Debugging line

  // Create EVP context
  EVP_MD_CTX *ctx = EVP_MD_CTX_new();
  if (!ctx) {
    THROW_ERROR(1, "Error creating EVP context");
  }

  if (1 != EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr)) {
    EVP_MD_CTX_free(ctx);
    THROW_ERROR(1, "Error initializing digest");
  }

  const size_t buffer_size = 8192;
  char buffer[buffer_size];
  while (file.read(buffer, buffer_size)) {
    if (1 != EVP_DigestUpdate(ctx, buffer, file.gcount())) {
      EVP_MD_CTX_free(ctx);
      THROW_ERROR(1, "Error updating hash");
    }
  }

  std::cout << "File reading complete." << std::endl; // Debugging line

  // Ensure the last block is processed if the file is not exactly a multiple of
  // buffer_size
  if (file.gcount() > 0 && 1 != EVP_DigestUpdate(ctx, buffer, file.gcount())) {
    EVP_MD_CTX_free(ctx);
    THROW_ERROR(1, "Error updating hash with the final block");
  }

  if (1 != EVP_DigestFinal_ex(ctx, hash, &hash_len)) {
    EVP_MD_CTX_free(ctx);
    THROW_ERROR(1, "Error finalizing hash");
  }

  EVP_MD_CTX_free(ctx);

  std::stringstream hex_hash;
  for (unsigned int i = 0; i < hash_len; ++i) {
    hex_hash << std::setw(2) << std::setfill('0') << std::hex << (int)hash[i];
  }

  return hex_hash.str();
}

} // namespace tsugou

#endif