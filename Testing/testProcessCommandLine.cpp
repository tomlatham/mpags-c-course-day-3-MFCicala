//! Unit Tests for MPAGSCipher ProcessCommandLine interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

TEST_CASE("Arguments for help are processed correctly", "[commandline]")
{

  std::vector<std::string> args{"","-h","--help"};
  ProgramSettings arguments;
  REQUIRE(processCommandLine(args, arguments) == true);
  REQUIRE(arguments.helpRequested == true);
}

TEST_CASE("Argument for version is processed correctly", "[commandline]")
{

  std::vector<std::string> args{"","--version"};
  ProgramSettings arguments;
  REQUIRE(processCommandLine(args, arguments) == true);
  REQUIRE(arguments.versionRequested == true);
}

TEST_CASE("Argument for input file without filename is processed correctly", "[commandline]")
{

  std::vector<std::string> args{"","-i"};
  ProgramSettings arguments;
  REQUIRE(processCommandLine(args, arguments) == false);
}

TEST_CASE("Arguments for input file are processed correctly", "[commandline]")
{

  std::vector<std::string> args{"","-i","InputFile"};
  ProgramSettings arguments;
  REQUIRE(processCommandLine(args, arguments) == true);
  REQUIRE(arguments.inputFile == "InputFile");
}

TEST_CASE("Argument for output file without filename is processed correctly", "[commandline]")
{

  std::vector<std::string> args{"","-o"};
  ProgramSettings arguments;
  REQUIRE(processCommandLine(args, arguments) == false);
}

TEST_CASE("Arguments for output file are processed correctly", "[commandline]")
{

  std::vector<std::string> args{"","-o", "OutputFile"};
  ProgramSettings arguments;
  REQUIRE(processCommandLine(args, arguments) == true);
  REQUIRE(arguments.outputFile == "OutputFile");
}

TEST_CASE("Argument for key without key is processed correctly", "[commandline]")
{

  std::vector<std::string> args{"","-k"};
  ProgramSettings arguments;
  REQUIRE(processCommandLine(args, arguments) == false);
}

TEST_CASE("Argument for key is processed correctly", "[commandline]")
{

  std::vector<std::string> args{"","-k","6"};
  ProgramSettings arguments;
  REQUIRE(processCommandLine(args, arguments) == true);
  REQUIRE(arguments.cipher_key == "6");
}

TEST_CASE("Argument for encryption is processed correctly", "[commandline]")
{

  std::vector<std::string> args{"","--encrypt"};
  ProgramSettings arguments;
  REQUIRE(processCommandLine(args, arguments) == true);
  REQUIRE(arguments.mode == CipherMode::Encrypt);
}

TEST_CASE("Argument for decryption is processed correctly", "[commandline]")
{

  std::vector<std::string> args{"","--decrypt"};
  ProgramSettings arguments;
  REQUIRE(processCommandLine(args, arguments) == true);
  REQUIRE(arguments.mode == CipherMode::Decrypt);
}
