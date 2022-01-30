#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int pos;
  string lakh, hajar, shata, ten, num, temp;
  vector<vector<string>> Bangla;
  vector<string> BanglaTemp;
  vector<string> result;
  bool check;

  while (cin >> num)
  {
    pos = num.size() - 1;
    check = true;
    while(pos >= 0)
    {
      for(int i = pos; i > pos - 2; i--)
      {
        if(i < 0)
        {
          check = false;
          break;
        }
        ten = num[i] + ten;
      }
      pos -= 2;

      for (int i = pos; i > pos - 1; i--)
      {
        if(i < 0)
        {
          check = false;
          break;
        }
        shata = num[i] + shata;
      }
      pos -= 1;

      for (int i = pos; i > pos - 2; i--)
      {
        if(i < 0)
        {
          check = false;
          break;
        }
        hajar = num[i] + hajar;
      }
      pos -= 2;

      for (int i = pos; i > pos - 2; i--)
      {
        if(i < 0)
        {
          check = false;
          break;
        }
        lakh = num[i] + lakh;
      }
      pos -= 2; 

      BanglaTemp.push_back(lakh);
      BanglaTemp.push_back(hajar);
      BanglaTemp.push_back(shata);
      BanglaTemp.push_back(ten);
      Bangla.push_back(BanglaTemp);

      lakh.clear(); hajar.clear(); shata.clear(); ten.clear();
      BanglaTemp.clear();

      if(check == false) break;
    }

    for(int kuti = Bangla.size() - 1; kuti >= 0; kuti--)
    {
      if(Bangla[kuti][0] != "00" && Bangla[kuti][0] != "0" && !Bangla[kuti][0].empty())
      {
        temp += " " + Bangla[kuti][0] + " lakh";
        if(Bangla[kuti][0][0] == '0')
          temp.erase(temp.end() - 7);
      }

      if(Bangla[kuti][1] !="00" && Bangla[kuti][1] != "0" && !Bangla[kuti][1].empty())
      {
        temp += " " + Bangla[kuti][1] + " hajar";
        if(Bangla[kuti][1][0] == '0')
          temp.erase(temp.end() - 8);
      }

      if(Bangla[kuti][2] != "0" && !Bangla[kuti][2].empty())
      {
        temp += " " + Bangla[kuti][2] + " shata";
        if(Bangla[kuti][2][0] == '0')
          temp.erase(temp.end() - 8);
      }

      if(Bangla[kuti][3] != "00" && !Bangla[kuti][3].empty())
      {
        if(kuti != 0 && Bangla[kuti][3] == "0")
          continue;
        temp += " " + Bangla[kuti][3];
        if(Bangla[kuti][3][0] == '0' && Bangla[kuti][3].size() != 1)
          temp.erase(temp.end() - 2);
      }

      if(kuti != 0)
        temp += " kuti";   
    }

    if(temp[1] == 'k')
      temp.erase(temp.begin() + 1, temp.begin() + 6);

    result.push_back(temp);
    Bangla.clear(); temp.clear();
  }
  
  for(int i = 0; i < result.size(); i++)
    cout << std::setw(4) << i + 1 << "." << result[i] << endl;
    
  return 0;
}