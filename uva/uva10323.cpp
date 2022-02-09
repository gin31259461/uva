#include <iostream>
#include <vector>

int main()
{
  std::vector<unsigned long int> dp(2);
  long long int lower_limit = 10000, upper_limit = 6227020800; 
  int lowerN, upperN;
 
  dp[0] = 1; dp[1] = 1;

  int i = 2;
  bool flag = true;
  while(dp[dp.size()-1] != upper_limit)
  {
    dp.push_back(dp[i-1] * i); i++; 
    if(dp[dp.size()-1] >= lower_limit && flag)
    {
      lowerN = dp.size()-1;
      flag = false;
    }
    else if (dp[dp.size()-1] <= upper_limit)
      upperN = dp.size()-1;
  }

  int n;
  while(std::cin >> n)
  {
    if(n < 0)
    {
      if(n * -1 % 2 == 0)
        std::cout << "Underflow!" << std::endl;
      else
        std::cout << "Overflow!" << std::endl;
      continue;
    }
    if(n > upperN)
      std::cout << "Overflow!" << std::endl;
    else if(n < lowerN)
      std::cout << "Underflow!" << std::endl;
    else
      std::cout << dp[n] << std::endl;
  }
  return 0;
}
