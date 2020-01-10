#include "lexer.hpp"

#include <fstream>
#include <iostream> 

Lexer::Lexer(std::string fileLoc, Dictionary &dictionary)
:
m_dictionary(dictionary)
{
  std::fstream file;
  file.open(fileLoc, std::fstream::in);
  if(!file)
    std::cerr << "no file" << std::endl;
  else
  {
    std::string line;
    while(std::getline(file, line))
    {
      std::string::size_type pos;
      while((pos = line.find("«")) != std::string::npos)
      {
        std::string::size_type delim = line.find_first_of(" \n", pos);
        std::string key = line.substr(pos + std::string("«").size(), delim - (pos + std::string("«").size()));
        std::cout << "key: " << key << std::endl;
        line.replace(pos, delim - pos, m_dictionary.getValue(key));
      }

      m_text.push_back(line);
    }
  }
}

void Lexer::writeOutput(std::string filename)
{
  std::fstream output;
  output.open(filename, std::fstream::out);

  for(std::string& i : m_text)
  {
    output << i << '\n';
  }

  output.close();
}
