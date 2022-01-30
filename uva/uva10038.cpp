#include <iostream>
#include <vector>

int main()
{
  int temp, cases;
  std::vector<int> seq;
  std::vector<bool> occur;

  while(std::cin >> cases)
  {
    for(int i = 0; i < cases; i++)
    {
      std::cin >> temp;
      seq.push_back(temp);
    }
    
    if(cases == 1)
    {
      std::cout << "Jolly" <<std::endl;
      continue;
    }

    occur.assign(cases - 1, false);
    for(int i = 1; i < seq.size(); i++)
    {
      int n = abs(seq[i] - seq[i - 1]);
      if(n < cases && n >= 1)
        occur[n - 1] = true;
    }
    
    for(int i = 0; i < occur.size(); i++)
    {
      if(occur[i] == false)
      {
        std::cout << "Not jolly" << std::endl;
        break;

      }else if(occur[i] == true && i == occur.size() - 1)
        std::cout << "Jolly" << std::endl;
    }

    occur.clear();
    seq.clear();
  }

  return 0;
}