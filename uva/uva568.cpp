#include <iostream>
#include <cstring>
#include <iomanip>

struct Bignum
{
public:
  int num[50000];
  int size;
  Bignum();
};

Bignum::Bignum()
{
  std::memset(num, 0, sizeof(num));
  size = 1;
}

int dp[10001];
int dp_index = 2;
Bignum fac[10001];

Bignum calculate_bignum_multiple(Bignum a, int b)
{
  int carry = 0;
  bool flag = true;
  Bignum tmp;

  for(tmp.size = 0; tmp.size < a.size || carry; tmp.size++)
  {
    tmp.num[tmp.size] = a.num[tmp.size] * b + carry;
    carry = tmp.num[tmp.size] / 10;
    tmp.num[tmp.size] %= 10;

    if(tmp.num[tmp.size] != 0 && flag)
    {
      flag = false;
      dp[dp_index] = tmp.num[tmp.size];
      dp_index++;
    }
  }
  if(tmp.num[tmp.size]) tmp.size++;
  return tmp;
}

int main()
{
  fac[0].num[0] = 1;
  fac[1].num[0] = 1;
  dp[0] = 1;
  dp[1] = 1;

  for(int i = 2; i <= 10000; i++)
    fac[i] = calculate_bignum_multiple(fac[i-1], i);
  
  int n;
  while(std::cin >> n && n != EOF)
    std::cout << std::setw(5) << n << " -> " << dp[n] << std::endl; 

  return 0;
}
