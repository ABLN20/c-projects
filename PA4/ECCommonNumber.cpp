// Given two arrays of integers, return true (and also store the smallest integer that is in both arrays). Return false if no such integer exists 
// For example, suppose A1={1, 5, 3, 1} and A2={3, 7, 2}. Then ECCommonNumber(A1, 4, A2, 3, val) would return true (and val would be 3 after function call returns). Here, A1 is the first array, 4 is the size of the first array, A2 is the second array and 3 is the size of the second array. 
// Note: you must implement your algorithm as efficiently as possible
// Also, you need to define the function yourself: how are you going to take
// Tip: don't reinvent the wheel; try to use C++ standard library functions

#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;


bool ECCommonNumber(const int arr1[], const int arr1Length, const int arr2[], const int arr2Length, int &valcommon)
{
  // your code here...
  vector<int> arr1Copy(arr1, arr1 + arr1Length);
  vector<int> arr2Copy(arr2, arr2 + arr2Length);
  sort(arr1Copy.begin(), arr1Copy.end());
  sort(arr2Copy.begin(), arr2Copy.end());
  int i = 0;
  int j = 0;
  while((i != arr1Length) && (j != arr2Length))
  {
    if (arr1Copy[i] == arr2Copy[j])
    {
      valcommon = arr1Copy[i];
      return true;
    }
    else if (arr1Copy[i] > arr2Copy[j])
    {
      j++;
    }
    else if (arr1Copy[i] < arr2Copy[j])
    {
      i++;
    }
  }
  return false;
}

