#include <vector>
#include <algorithm>

// count and return the number of integers in vec that are non-negative
int ECCountNonNegatives(const std::vector<int> &vec)
{
  // Your code here
  // Please use std::for_each and Lambda...
  int count = 0;

  std::for_each(vec.begin(), vec.end(), [&count](int x) 
  {
    if (x >= 0) 
    {
      count++;
    }
  });

  return count;
}
