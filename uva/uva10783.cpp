#include <iostream>

int main()
{
  int cases;
  int r1, r2, sum;

  std::cin >> cases;
  for(int count = 0; count < cases; count++)
  {
    std::cin >> r1 >> r2;

    if(r1 % 2 == 0)
      r1 += 1;
    
    sum = 0;
    for(int i = r1; i <= r2; i += 2)
      sum += i;

    std::cout << "Case " << count + 1 << ": " << sum << std::endl;
  }
  return 0;
}