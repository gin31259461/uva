#include <iostream>
#include <string>
#include <vector>

int main()
{
  short testcase;
  std::cin >> testcase;

  std::string name;
  std::vector<short> tmp;
  std::vector<std::vector<short>> snowboard;
  short r, c, n;

  for(int cases = 0; cases < testcase; cases++)
  {
    std::cin >> name >> r >> c; 
    for(short i = 0; i < r; i++)
    {
      for(short j = 0; j < c; j++)
      {
        std::cin >> n;
        tmp.push_back(n);
      }
      snowboard.push_back(tmp);
      tmp.clear();
    }
  }

  /*
  std::cout << name << std::endl;
  for(int i = 0; i < snowboard.size(); i++)
  {
    for(int j = 0; j < snowboard[i].size(); j++)
      std::cout << snowboard[i][j] << " ";
    std::cout << std::endl;
  }
  */

  return 0;
}
