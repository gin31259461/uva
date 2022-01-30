#include <iostream>

int main()
{
  int v, t, d;

  while(std::cin >> v >> t)
  {
    d = v * t * 2;
    std::cout << d << std::endl;
  }

  return 0;
}