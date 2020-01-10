#include "translation/dictionary.hpp"
#include "translation/lexer.hpp"
#include "util/argumentparser.hpp"

#include <cstring>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  ArgumentParser parser(argc - 1, argc > 1 ? &(argv[1]) : nullptr);
  Dictionary dictionary(parser.getValue("dict"));

  Lexer lexer(parser.getValue("in"), dictionary);
  lexer.writeOutput(parser.getValue("out"));
  return 0;
}
