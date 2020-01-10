#include "argumentparser.hpp"

ArgumentParser::ArgumentParser(int argc, char **argv)
{
  for(int i = 0; i < argc; i++)
  {
    std::string temp = argv[i];
    std::string key;
    if(temp[0] == '-')
      key = temp.substr(1);

    if(!key.empty())
    {
      if(key == "help")
        m_arguments[key] = "true";
      else if(i + 1 < argc)
      {
        std::string value = argv[++i];
        m_arguments[key] = value;
      }
    }
  }
}

std::string ArgumentParser::getValue(std::string key)
{
  std::string retValue = "";
  if(m_arguments.find(key) != m_arguments.end())
    retValue = m_arguments[key];

  return retValue;
}
