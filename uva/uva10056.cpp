#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <math.h>

int main()
{
  int casenum, N, I;
  int R = 100000;
  double p, q, a1, r, result;

  std::cin >> casenum;
  for(int count = 0; count < casenum; count++)
  {
    std::cin >> N >> p >> I;

    if(p == 0.0)
    {
      printf("%.4f\n", 0.0);
      continue;
    }

    q = 1 - p;
    a1 = pow(q, I-1) * p;
    r = pow(q, N);
    result = a1 * (1 - pow(r, R)) / (1 - r);
    
    printf("%.4f\n", result);
    /*
      std::cout << std::fixed;
      std::cout << std::setprecision(4);
      std::cout << result << std::endl;
    */
  }
  return 0;
}