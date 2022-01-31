#include <iostream>

int main()
{
  int dp[77];  
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;

  for(int i = 3; i <= 76; i++)
    dp[i] = dp[i-2] + dp[i-3];

  dp[0] = 0;
  int n;

  while(std::cin >> n && n != EOF)
    std::cout << dp[n] << std::endl;

  return 0;
}
