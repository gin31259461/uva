#include <iostream>

int main()
{
  int cases, s, d, a, b, test1, test2;

  std::cin >> cases;
  for(int count = 0; count < cases; count++)
  {
    std::cin >> s >> d;

    test1 = (s + d) / 2;
    test2 = (s - d) / 2;

    if((a = s - test1) < 0 || (b = test1) < 0)
      if((a = s - test2) < 0 || (b = test2) < 0)
      {
        std::cout << "impossible" << std::endl;
        continue;
      }
    
    if(abs(a - b) != d)
    {
      std::cout << "impossible" << std::endl;
      continue;
    }

    if(a > b)
      std::cout << a << " " << b << std::endl;
    else
      std::cout << b << " " << a << std::endl;
    
  }

  return 0;
}