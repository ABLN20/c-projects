#include <vector>
#include <iostream>
using namespace std;

// return the sum of the numbers
int ECSumList(const vector<int> &listNums)
{
  // your code goes here ...
  int total = 0;
  for (int i: listNums)
  {
    total += i;
  }
  return total;
}

