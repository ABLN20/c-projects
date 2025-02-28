#include <set>
#include <vector>
#include <iostream>
using namespace std;

int ECSumList(const set<int> &listNums)
{
  // your code goes here ...
  int total = 0;
  for (int i: listNums)
  {
    total += i;
  }
  return total;
}

