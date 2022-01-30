#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
std::vector<int> bottles;

void solution()
{
  int total = 0;
  int step[6];
  std::string str[6] = {"BGC", "BCG", "GBC", "GCB", "CBG", "CGB"};

  for(int i=0; i < bottles.size(); i++)
    total += bottles[i];
  
  // 0 1 2 3 4 5 6 7 8
  // B G C B G C B G C
  step[0] = total - bottles[0] - bottles[4] - bottles[8]; //BGC
  step[1] = total - bottles[0] - bottles[5] - bottles[7]; //BCG 
  step[2] = total - bottles[1] - bottles[3] - bottles[8]; //GBC 
  step[3] = total - bottles[1] - bottles[5] - bottles[6]; //GCB
  step[4] = total - bottles[2] - bottles[3] - bottles[7]; //CBG 
  step[5] = total - bottles[2] - bottles[4] - bottles[6]; //CGB 
   
  int v = step[0], index = 0;
  for(int i=1; i < 6; i++)
  {
    if(step[i] < v) 
    {
      v = step[i];
      index = i;
    }
    else if(step[i] == v)
    {
      if(str[i] < str[index])
      {
        v = step[i];
        index = i;
      }
    }
  }
  cout << str[index] << " " << v << std::endl;
}

int main()
{
  std::stringstream ss;
  std::string line;
  int tmp;
  
  while(!cin.eof())
  {
    std::getline(cin, line);

    if(line.empty())
      continue;

    ss << line;
    while(ss >> tmp)
      bottles.push_back(tmp);
    
    solution();
    bottles.clear();
    ss.clear();
    line.clear();
  }
  return 0;
}
