#include <iostream>
using namespace std;

int ECRemoveSpace(int nums[], int len, int val)
{
  // your code here
  int start = 0;
  int end = len - 1;
  int temp;
  int count = 0;
  while (true)
  {
    if (start == end)
    {
      return len - count -1;
    }
    if (nums[end] == val)
    {
      end--;
      continue;
    }
    if (nums[start] == val)
    {
      temp = nums[start];
      nums[start] = nums[end];
      nums[end] = temp;
      start++;
      end--;
      count++;
    }
    else
    {
      start++;
    }
  }
  
}


