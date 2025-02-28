#include <vector>
using namespace std;

bool ECFind(const vector<int> &listVecs, int x)
{
  // your code goes here ...
  for (int i: listVecs)
  {
    if (i == x)
    {
      return true;
    }
    
  }
  return false;
}

