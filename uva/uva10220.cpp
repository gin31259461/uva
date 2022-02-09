#include <iostream>
#include <cstring>

struct Bignum
{
  int num[3000];
  int size;
  Bignum();
};

Bignum::Bignum()
{
  std::memset(num, 0, sizeof(num)); 
  size = 1;
}

Bignum fac[1001];
int dp[1001];
int dp_index = 2;

Bignum calculate_bignum_multiple(Bignum a, int b)
{
  int carry = 0;
  int sum = 0;
  Bignum tmp;

  for(tmp.size = 0; tmp.size < a.size || carry; tmp.size++)
  {
    tmp.num[tmp.size] = a.num[tmp.size] * b + carry;
    carry = tmp.num[tmp.size] / 10;
    sum += (tmp.num[tmp.size] %= 10);
  }
  if(tmp.num[tmp.size]) tmp.size++;
  dp[dp_index] = sum;
  dp_index++;
  return tmp;
}

int main()
{
  fac[0].num[0] = 1;
  fac[1].num[0] = 1;
  dp[0] = 1;
  dp[1] = 1;

  for(int i = 2; i <= 1000; i++)
    fac[i] = calculate_bignum_multiple(fac[i-1], i);
  
  int n;
  while(std::cin >> n && n != EOF)
    std::cout << dp[n] << std::endl;

  return 0;
}
