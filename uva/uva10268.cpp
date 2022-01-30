#include <iostream>
#include <sstream>
#include <string>
#include <vector>

long long int power(long long int x, long unsigned int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;
  
  long long int tmp = power(x, p / 2);
  if (p % 2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

void derivative(std::vector<long long int> &p)
{
  p.pop_back();
  for(int i = p.size() - 1, count = 1; i >= 0; count++, i--)
    p[i] *= count;
}

long long int calculate(std::vector<long long int> p, long long int x)
{
  long long int result = 0;
  for(int i = p.size() - 1, count = 0; i >= 0; count++, i--)
    result += p[i] * power(x, count);
  
  return result;
}

int main()
{
  long long int x, temp, result;
  std::vector<long long int> p;
  std::string line;

  while(std::cin >> x)
  {
    std::cin.ignore(1, '\n');
    std::getline(std::cin, line);

    if(line.empty())
      continue;

    std::istringstream ss(line);   

    while(ss >> temp)
      p.push_back(temp);
      
    derivative(p);
    result = calculate(p, x);
    std::cout << result << std::endl;
    p.clear();
  }

  return 0;
}