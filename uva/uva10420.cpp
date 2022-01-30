#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::string;

bool CountryNameCompare(string str1, string str2)
{
  return str1 < str2;
}

int main()
{
  unsigned int nline, count;
  map<string, int> record;
  vector<string> country;
  string temp, found;

  cin >> nline;
  cin.ignore();
  for(unsigned int n = 0; n < nline; n++)
  {
    
    std::getline(cin, temp);
    int p1 = temp.find_first_not_of(' ');
    int p2 = temp.find(' ', p1);
    found.assign(temp, p1, p2);

    auto it = record.find(found);
    if(it == record.end())
    {
      country.push_back(found);
      record.insert(std::pair<string, int>(found, 1));
    }
    else 
      record[found]++;

    found.clear();
  }

  std::sort(country.begin(), country.end(), CountryNameCompare);

  for(unsigned int i = 0; i < country.size(); i++)
    cout << country[i] << " " << record[country[i]] << endl;

  return 0;
}