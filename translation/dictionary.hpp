#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <map>

class Dictionary
{
public:

  Dictionary(std::string fileLoc);
  std::string getValue(std::string key);

private:

  void parseFile(std::fstream &file);

  std::map<std::string, std::string> m_symboldic;

};

#endif
