#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
  long long int army1, army2, temp;
  vector<long long int> diff;

  while (cin >> army1 >> army2)
  {
    if (army1 >= army2)
      temp = army1 - army2;
    else
      temp = army2 - army1;
    diff.push_back(temp);
  }

  for (int i = 0; i < diff.size(); i++)
    cout << diff[i] << endl;

  return 0;
}