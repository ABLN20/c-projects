// Starter code
#include <iostream>

using namespace std;

string ECStringSep(const string &str)
{
  string res;
  // your code goes here
  for (size_t i = 0; i < str.length(); i++)
  {
    res += str[i];
    res += ',';
  }

  if (!res.empty()) {
    res.pop_back();
  }
    
  return res;
}

