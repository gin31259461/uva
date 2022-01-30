#include <iostream>
#include <vector>

int main()
{
  int casenum, tempdays = 0, dateindex = 0, idx;
  unsigned int M, D;
  const char dates[][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  
  for(int count = 0; count < 4 + 31 + 28 + 31; count++)
  {
    if(dateindex != 0)
      dateindex--;
    else if(dateindex == 0)
      dateindex = 6;
  }
  
  std::cin >> casenum;
  for(int count = 0; count < casenum; count++)
  {
    std::cin >> M >> D;

    for(int i = 1; i < M; i++)
    {
      if(i == 2)
        tempdays += 28;
      else if(i % 2 != 0 && i <= 7)
        tempdays += 31;
      else if(i % 2 == 0 && i >= 8)
        tempdays +=31;
      else
        tempdays +=30;
    }
    
    idx = dateindex;
    for(int i = 0; i < tempdays + D; i++)
    {
      if(idx != 6)  idx++;
      else if(idx == 6) idx = 0;
    }

    std::cout << dates[idx] << std::endl;
    tempdays = 0;
  }
  return 0;
}