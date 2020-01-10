#include "dictionary.hpp"

#include <fstream>
#include <iostream>

Dictionary::Dictionary(std::string fileLoc)
{
  std::fstream file;
  file.open(fileLoc, std::fstream::in);

  if(!file)
    std::cerr << "Dictionary file specified does not exist." << std::endl;
  else
    parseFile(file);
}

std::string Dictionary::getValue(std::string key)
{
  return m_symboldic[key];
}

void Dictionary::parseFile(std::fstream &file)
{
  std::string line;

  while(std::getline(file, line))
  {
    std::string::size_type delim = line.find(',');
    std::string key = line.substr(0, delim);
    std::string value = line.substr(delim + 1, line.size() - 1);
    
    m_symboldic[key] = value;
  }
}
