#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::vector;
using std::string;

vector<vector<int>> blocks;
vector<int> currentPos;

bool check_same_pos(int n1, int n2)
{
  if(currentPos[n1] == currentPos[n2])
    return true;
  else
    return false;
}

void put_back(int n)
{
  int p = currentPos[n];
  int tmp;

  for(int i = blocks[p].size()-1; i >= 0; i--)
  {
    tmp = blocks[p][i];
    if(tmp == n)
      break;
    else
    {
      blocks[tmp].push_back(tmp);
      blocks[p].pop_back();
      currentPos[tmp] = tmp;
    }
  }
}

void move(int n1, int n2)
{
  int p1 = currentPos[n1];  
  int p2 = currentPos[n2];

  blocks[p2].push_back(n1);
  blocks[p1].pop_back();
  currentPos[n1] = p2;
}

void pile_move(int n1, int n2)
{
  int p1 = currentPos[n1];
  int p2 = currentPos[n2];
  int index, count = 0, tmp;

  for(int i = 0; i < blocks[p1].size(); i++)
    if(blocks[p1][i] == n1)
    {
      index = i;
      break;
    }

  for(int i = index; i < blocks[p1].size(); i++)
  {
    tmp = blocks[p1][i];
    blocks[p2].push_back(tmp);
    currentPos[tmp] = p2;
    count++;
  }

  for(int i = 0; i < count; i++)
    blocks[p1].pop_back();
}

void print()
{
  for(int i = 0; i < blocks.size(); i++)
  {
    cout << i << ":";
    for(int j = 0; j < blocks[i].size(); j++)
      cout << " " << blocks[i][j];
    cout << std::endl;
  }
}

int main()
{
  int bnum, n1, n2;
  string ope1, ope2;

  cin >> bnum;
  vector<int> tmp(1, 0);
  for(int i = 0; i < bnum; i++) 
  {
    tmp[0] = i;
    blocks.push_back(tmp);
    currentPos.push_back(i);
  }

  while(cin >> ope1) 
  {
    if(ope1 == "quit")
    {
      print();
      break;
    }

    cin >> n1 >> ope2 >> n2;
    
    if(check_same_pos(n1, n2)) 
      continue;

    if(ope1 == "move")
    {
      if(ope2 == "onto")
      {
        put_back(n1);
        put_back(n2);
        move(n1, n2);
      }
      else if(ope2 == "over")
      {
        put_back(n1);
        move(n1, n2);
      }
    }
    else if(ope1 == "pile")
    {
      if(ope2 == "onto")
      {
        put_back(n2);
        pile_move(n1, n2);
      }
      else if(ope2 == "over")
        pile_move(n1, n2);
    }
  }
  return 0;
}
