#include <iostream>

int main()
{
  long long int initialSize, dayNum;

  while(std::cin >> initialSize >> dayNum)
  {
    for(long long int i = 1; i <= dayNum; initialSize++, i++)
    {
      i += initialSize - 1;
    }
    initialSize--;
    std::cout << initialSize << std::endl;
  }
  return 0;
}
