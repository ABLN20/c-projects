// Starter code
#include <string>
#include <iostream>

using namespace std;

string ECSwapCase(string str)
{
  // your code here...
  string res;

  for (size_t i = 0; i < str.length(); i++)
  {
    if (isupper(str[i]))
    {
      res += tolower(str[i]);
    }
    else
    {
      res += toupper(str[i]);
    }
  }
  return res;
}

