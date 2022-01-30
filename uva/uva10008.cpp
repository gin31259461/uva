#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <ctype.h>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::string;

map<char, int> LetterRecord;

bool Cmp(char c1, char c2)
{
  if(LetterRecord[c1] == LetterRecord[c2]) return c1 < c2;
  return LetterRecord[c1] > LetterRecord[c2];
}

int main()
{
  unsigned int nline;
  string readline;
  vector<char> Letters;

  cin >> nline;
  cin.ignore();
  for (unsigned int i = 0; i < nline; i++)
  {
    std::getline(cin, readline);
    for(auto it = readline.begin(); it != readline.end(); it++)
    {
      char templ = towlower(*it);
      char tempu = toupper(templ);
      if(tempu == templ) continue;

      auto mapit = LetterRecord.find(tempu);
      if(mapit == LetterRecord.end())
      {
        Letters.push_back(tempu);
        LetterRecord.insert(std::pair<char, int>(tempu, 1));
      }
      else
        LetterRecord[tempu]++;
    }
  }

  std::sort(Letters.begin(), Letters.end(), Cmp);

  for(int i = 0; i < Letters.size(); i++)
    cout << Letters[i] << " " << LetterRecord[Letters[i]] << endl;
    
  return 0;
}