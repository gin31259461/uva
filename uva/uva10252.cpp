#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

bool Cmp(char c1, char c2)
{
  return c1 < c2;
}

int main()
{
  int p;
  std::string str1, str2, x;
  std::vector<std::string> result;

  while(std::getline(std::cin, str1) && std::getline(std::cin, str2))
  {
    for(int i = 0; i < str2.size(); i++)
      if((p = str1.find(str2[i])) != std::string::npos)
      {
        str1[p] = '0';
        x.push_back(str2[i]);
      }
    
    if(x.size() == 0)
    {
      result.push_back(" ");
      continue;
    }
    else
    {
      std::sort(x.begin(), x.end(), Cmp);
      result.push_back(x);
    }

    x.clear();
  }

  for(int i = 0; i < result.size(); i++)
  {
    if(result[i] == " ")
    {
      std::cout << std::endl;
      continue;
    }
    else
      std::cout << result[i] << std::endl;
  }
}