#include <iostream>
#include <string>
#include <vector>

int main()
{
  std::string readline;
  std::vector<std::string> output;
  int status = 1, p;

  while(std::getline(std::cin, readline))
  {
    while(1)
    {
      p = readline.find('"');

      if(p == std::string::npos)
        break;
      else if(status == 1)
      { 
        readline[p] = '`';
        readline.insert(p + 1, 1, '`');
        status = 2;
      }
      else if(status == 2)
      {
        readline[p] = '\'';
        readline.insert(p + 1, 1, '\'');
        status = 1;
      }
    }

    output.push_back(readline);
  }

  for(int i = 0; i < output.size(); i++)
    std::cout << output[i] << std::endl;
  
  return 0;
}