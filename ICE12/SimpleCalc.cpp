#include <cmath>

int SimpleCalc(int x, int y)
{
  // write one line of code to return
  // (i) if y >=0, x^y (ii) otherwise reutrn x*y
  return (y >= 0) ? pow(x, y) : x * y;
}
