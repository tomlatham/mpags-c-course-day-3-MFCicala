#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>
#include "CipherMode.hpp"

//! Encrypt or decrypt text using the Caesar cipher with the given key
class CaesarCipher {
public:
  explicit CaesarCipher( const size_t key);
  explicit CaesarCipher( const std::string key);

  std::string applyCipher(std::string inputText, CipherMode mode) const;

private:  
  size_t key_;
  const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  const size_t alphabetSize_ {alphabet_.size()};

};

#endif
