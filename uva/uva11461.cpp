#include <iostream>
#include <cmath>

int main()
{
  int a, b, r1, r2;
  bool findr1, findr2;
  while(std::cin >> a >> b && a > 0 && b > 0)
  {
    findr1 = false;
    findr2 = false;
    
    r1 = 0;
    r2 = 0;

    while(a <= b)
    {
      if(findr1 == false)
        r1 = (int)sqrt(a);
      
      if(findr2 == false)
        r2 = (int)sqrt(b);

      if(r1 * r1 == a)
        findr1 = true;
      else
        a++;
      
      if(r2 * r2 == b)
        findr2= true;
      else
        b--;

      if(findr1 == true && findr2 == true)
        break;
    }
    
    if(findr1 == true && findr2 == true)
      std::cout << r2 - r1 + 1 << std::endl;
    else
      std::cout << 0 << std::endl;
  }

  return 0;
}