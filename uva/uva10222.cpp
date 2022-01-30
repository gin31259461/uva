#include <iostream>
#include <string>
#include <ctype.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int Decode(char c, string &container)
{
  string decode[3] =
  {
    "qwertyuiop[]", "asdfghjkl;'", "zxcvbnm,."
  };

  if(c == ' ')
  {
    container.push_back(' ');
    return 0;
  }

  for(int j = 0; j < 3; j++)
   for(int i = 2; i < decode[j].size(); i++)
     if(c == decode[j][i])
     {
       container.push_back(decode[j][i - 2]);
       return 0;
     }

  return -1;
}

int main()
{
  string readline, result;
  std::getline(cin, readline);
  
  for(int i = 0; i < readline.size(); i++)
    Decode(tolower(readline[i]), result);

  cout << result << endl;
  return 0;
}