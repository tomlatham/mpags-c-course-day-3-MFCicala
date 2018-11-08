// Standard Library includes
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Our project headers
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "CaesarCipher.hpp" 
#include "CipherMode.hpp"

  
// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  ProgramSettings arguments {false, false, "","","", CipherMode::Encrypt};

  // Process command line arguments
  bool cmdLineStatus { processCommandLine(cmdLineArgs, arguments) };

  // Any failure in the argument processing means we can't continue
  // Use a non-zero return value to indicate failure
  if( !cmdLineStatus ) {
    return 1;
  }

  // Handle help, if requested
  if (arguments.helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>] [-k <key>] [--encrypt/--decrypt]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n"
      << "  -k KEY           Specify the cipher KEY\n"
      << "                   A null key, i.e. no encryption, is used if not supplied\n\n"
      << "  --encrypt        Will use the cipher to encrypt the input text (default behaviour)\n\n"
      << "  --decrypt        Will use the cipher to decrypt the input text\n\n";
    // Help requires no further action, so return from main,
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  if (arguments.versionRequested) {
    std::cout << "0.3.0" << std::endl;
    // Like help, requires no further action, so return from main,
    // with 0 used to indicate success
    return 0;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // Read in user input from stdin/file
  if (!arguments.inputFile.empty()) {

    // Open the file and check that we can read from it
    std::ifstream inputStream(arguments.inputFile);
    if (!inputStream.good()) {
      std::cerr << "[error] failed to create istream on file '" << arguments.inputFile << "'" << std::endl;
      return 1;
    }

    // Loop over each character from the file
    while(inputStream >> inputChar)
    {
      inputText += transformChar(inputChar);
    }

  } else {

    // Loop over each character from user input
    // (until Return then CTRL-D (EOF) pressed)
    while(std::cin >> inputChar)
    {
      inputText += transformChar(inputChar);
    }
  }


  // Run the Caesar cipher (using the specified key and encrypt/decrypt flag) on the input text
  CaesarCipher myCipher(arguments.cipher_key);
  std::string outputText { myCipher.applyCipher(inputText, arguments.mode) }; 

  // Output the transliterated text
  if (!arguments.outputFile.empty()) {

    // Open the file and check that we can write to it
    std::ofstream outputStream(arguments.outputFile);
    if (!outputStream.good()) {
      std::cerr << "[error] failed to create ostream on file '" << arguments.outputFile << "'" << std::endl;
      return 1;
    }

    // Print the transliterated text to the file
    outputStream << outputText << std::endl;

  } else {

    // Print the transliterated text to the screen
    std::cout << outputText << std::endl;
  }

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}
