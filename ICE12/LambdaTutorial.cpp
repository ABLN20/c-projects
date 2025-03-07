#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// compare function; for function pointer
bool cmp0(int x, int y)
{
  return x > y;
}

// sorting
void mysort(vector<int> &v)
{
  // function pointer
  std::sort(v.begin(), v.end(), cmp0);
}


// testing
int main()
{
  vector<int> v;
  v.push_back(3);
  v.push_back(1);
  v.push_back(2);
  v.push_back(6);
  v.push_back(4);
  mysort(v);
  cout << "v: ";
  for(auto x: v)
  {
    cout << x << " ";
  }
  cout << endl;
}

