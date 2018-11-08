//! Unit Tests for MPAGSCipher CaesarCipher interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"

TEST_CASE("Text is encrypted with key passed as a string", "[caesar]")
{
  const std::string key{"16"};
  std::string inputText{"HELLOWORLD"};
  CaesarCipher MyCipher(key);
  CipherMode mode{CipherMode::Encrypt};
  REQUIRE(MyCipher.applyCipher(inputText, mode)=="XUBBEMEHBT");
}

TEST_CASE("Text is encrypted with key passed as a number", "[caesar]")
{
  const size_t key{16};
  std::string inputText{"HELLOWORLD"};
  CaesarCipher MyCipher(key);
  CipherMode mode{CipherMode::Encrypt};
  REQUIRE(MyCipher.applyCipher(inputText, mode)=="XUBBEMEHBT");
}

TEST_CASE("Text is decrypted with key passed as a string", "[caesar]")
{
  const std::string key{"16"};
  std::string inputText{"XUBBEMEHBT"};
  CaesarCipher MyCipher(key);
  CipherMode mode{CipherMode::Decrypt};
  REQUIRE(MyCipher.applyCipher(inputText, mode)=="HELLOWORLD");
}

TEST_CASE("Text is decrypted with key passed as a number", "[caesar]")
{
  const size_t key{16};
  std::string inputText{"XUBBEMEHBT"};
  CaesarCipher MyCipher(key);
  CipherMode mode{CipherMode::Decrypt};
  REQUIRE(MyCipher.applyCipher(inputText, mode)=="HELLOWORLD");
}

