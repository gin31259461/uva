#include <iostream>
#include <vector>
#include <string>

int FindGn(std::string n)
{
  int temp = 0;
  char c;

  if(n.size() == 1) return atoi(&n[0]);

  for(auto it = n.begin(); it != n.end(); it++)
  {
    c = *it;
    temp += atoi(&c);
  }
  
  auto rts = std::to_string(temp);
  return FindGn(rts);
}

int main()
{
  std::string input;
  std::vector<int> output;

  while(std::cin >> input && input != "0")
    output.push_back(FindGn(input));
  
  for(int i = 0; i < output.size(); i++)
    std::cout << output[i] << std::endl;
  
  return 0;
}