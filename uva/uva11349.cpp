#include <iostream>
#include <vector>

bool symmetric(std::vector<long long int> matrix)
{
  for(int start = 0, end = matrix.size() - 1; start <= end; start++, end--)
  {
    if(matrix[start] != matrix[end])
      return false;
    if(start == end && matrix[start] < 0)
      return false;
  }
  return true;
}

int main()
{
  int cases, n;
  long long int temp;
  char N, symbol;
  std::vector<long long int> matrix;

  std::cin >> cases;
  for(int count = 0; count < cases; count++)
  {
    std::cin >> N >> symbol >> n;
    for(int i = 0; i < n * n; i++)
    {
      std::cin >> temp;
      matrix.push_back(temp);
    }

    if(symmetric(matrix) == true)
      std::cout << "Test #" << count + 1 << ": Symmetric." << std::endl;
    else
      std::cout << "Test #" << count + 1 << ": Non-symmetric." << std::endl;
    
    matrix.clear();
  } 
  return 0; 
}