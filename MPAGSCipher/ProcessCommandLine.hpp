#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>

#include "CipherMode.hpp"

struct ProgramSettings {
  bool helpRequested;
  bool versionRequested;
  std::string inputFile;
  std::string outputFile;
  std::string cipher_key;
  CipherMode mode;
};

bool processCommandLine(const std::vector<std::string>& args,
                        ProgramSettings& arguments);



#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP 
