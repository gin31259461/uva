#include <iostream>
#include <cstring>

class Bignum
{
public:
  int num[3000];
  int size;
  Bignum();
};

Bignum::Bignum()
{
  std::memset(num, 0, sizeof(num));
  size = 1;
}

Bignum dp[1001]; //must put here 
Bignum calculate_bignum_multiple(Bignum a, int b)
{
  int carry = 0;
  Bignum tmp;

  for(tmp.size = 0; tmp.size < a.size || carry; tmp.size++)
  {
    tmp.num[tmp.size] = a.num[tmp.size] * b + carry;
    carry = tmp.num[tmp.size] / 10;
    tmp.num[tmp.size] %= 10;
  }
  if(tmp.num[tmp.size]) tmp.size++;
  return tmp;
}

void print_bignum(Bignum a)
{
  for(int i = a.size-1; i >= 0; i--)
    std::cout << a.num[i];
  std::cout << std::endl;
}

int main()
{
  dp[0].num[0] = 1;
  dp[1].num[0] = 1;

  for(int i = 2; i <= 1000; i++)
    dp[i] = calculate_bignum_multiple(dp[i-1], i);

  int n;
  while(std::cin >> n && n != EOF)
  {
    std::cout << n << "!" << std::endl;
    print_bignum(dp[n]); 
  }
  return 0;
}
