#include <vector>
#include <map>
#include <iostream>
using namespace std;

void ECCountDistinct(const vector<int> &listNums, map<int,int> &mapDistinct)
{
  // your code goes here ...
  for (int i: listNums)
  {
    mapDistinct[i]++;
  }
}

