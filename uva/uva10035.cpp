#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void CalculateCarry(long long int num1, long long int num2, vector<int> &carry)
{
  int carrycount = 0;
  long long int range;

  if (num1 == 0 || num2 == 0)
    range = 0;
  else if (num1 >= num2)
    range = num1;
  else
    range = num2;

  for (long long int i = 10; i < range * 10; i *= 10)
    if ((num1 % i) + (num2 % i) >= i)
      carrycount++;

  carry.push_back(carrycount);
}

int main()
{
  long long int num1, num2;
  vector<int> carry;

  while (cin >> num1 >> num2)
  {
    if (num1 == 0 && num2 == 0)
      break;
    CalculateCarry(num1, num2, carry);
  }

  for (int i = 0; i < carry.size(); i++)
  {
    if (carry[i] == 0)
      cout << "No carry operation." << endl;
    else if (carry[i] == 1)
      cout << "1 carry operation." << endl;
    else
      cout << carry[i] << " carry operations." << endl;
  }

  return 0;
}
