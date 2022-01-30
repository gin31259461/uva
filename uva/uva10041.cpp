#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using std::vector;
using std::endl;
using std::cin;
using std::cout;
using std::sort;

void count_distance(vector<int> &res, vector<int> &arr)
{
	int sum = 0, size, mid;
  sort(arr.begin(), arr.end());

  size = arr.size();
  if(size % 2 != 0) //odd
    mid = arr[(size - 1) / 2 + 1 - 1];
  else //even
    mid = arr[size / 2 - 1];
  
  for(int i = 0; i < size; i++)
    sum += abs(mid - arr[i]);

  res.push_back(sum);
}

int main()
{
  int testcase, relatives, i = 0, j = 0;
  vector<int> street, result;

  cin >> testcase;
  while(i < testcase)
  {
    cin >> relatives;
    street.assign(relatives, 0);
    while(j < relatives)
    {
      cin >> street[j];
      j++;
    }
    count_distance(result, street);
    street.clear();
    i++; j = 0;
  }

  for(int i = 0; i < result.size(); i++)
    cout << result[i] << endl;

  return 0;
}