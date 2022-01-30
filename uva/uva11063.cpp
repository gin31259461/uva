#include <iostream>
#include <map>
#include <vector>

int main()
{
  int cases, temp, tempsum;
  int count = 0;
  std::map<int, int> sum;
  std::vector<int> sequence;
  bool duplicate, checkZero;

  while(std::cin >> cases)
  {
    duplicate = true;
    checkZero = false;

    for(int i = 0; i < cases; i++)
    {
      std::cin >> temp;
      if(temp < 1)
      {
        duplicate = false;
        std::cin.ignore(1024, '\n');
        goto check;
      }
      else if(i > 0 && temp < sequence[i - 1])
      {
        duplicate = false;
        std::cin.ignore(1024, '\n');
        goto check;
      }
      sequence.push_back(temp);
    }
    
    for(int i = 0; i < sequence.size(); i++)
      for(int j = i; j < sequence.size(); j++)
      {
        tempsum = sequence[i] + sequence[j];

        if(sum.find(tempsum) == sum.end())
          sum.insert(std::pair<int, int>(tempsum, 1));
        else
          sum[tempsum]++;
      }

    for(std::map<int, int>::iterator it = sum.begin(); it != sum.end(); it++)
      if(it->second > 1)
      {
        duplicate = false;
        break;
      }

  check:      
  
    if(duplicate == true)
      std::cout << "Case #" << count + 1 << ": It is a B2-Sequence." << std::endl << std::endl;
    else
      std::cout << "Case #" << count + 1 << ": It is not a B2-Sequence." << std::endl << std::endl;
    
    sum.clear();
    sequence.clear();
    count++;
  }
  return 0;
}