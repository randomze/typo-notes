#ifndef LEXER_H
#define LEXER_H

#include "dictionary.hpp"

#include <string>
#include <vector>

class Lexer
{
public:

  Lexer(std::string fileLoc, Dictionary &dictionary);

  void writeOutput(std::string filename);

private:

  Dictionary& m_dictionary;
  std::vector<std::string> m_text;
  std::string m_delim;

};

#endif
