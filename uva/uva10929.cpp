#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  string s, temp;
  vector<string> num;
  vector<bool> mul11;
  int even, odd;

  while (cin >> s && s != "0")
  {
    num.push_back(s);
    even = 0;
    odd = 0;

    for (unsigned int i = 0; i < s.size(); i++)
    {
      temp = s[i];
      if ((i + 1) % 2 != 0) //odd bit
        odd += std::stoi(temp);
      else //even bit
        even += std::stoi(temp);
    }

    if (abs(even - odd) % 11 == 0)
      mul11.push_back(true);
    else
      mul11.push_back(false);
  }

  for (int i = 0; i < mul11.size(); i++)
  {
    if (mul11[i] == true)
      cout << num[i] << " is a multiple of 11." << endl;
    else
      cout << num[i] << " is not a multiple of 11." << endl;
  }
  
  return 0;
}