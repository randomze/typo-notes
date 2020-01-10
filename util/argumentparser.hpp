#ifndef ARGUMENT_PARSER_HPP
#define ARGUMENT_PARSER_HPP

#include <map>
#include <string>

//The ArgumentParser class expects the argv table and its respective argc
//to be already adjusted as to not have the file name.
class ArgumentParser
{
public:

  ArgumentParser(int argc, char **argv);
  std::string getValue(std::string key);

private:

  std::map<std::string, std::string> m_arguments;

};
#endif
