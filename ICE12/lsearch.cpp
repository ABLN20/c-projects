// Modify the following code so that it uses lambda for compare
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double delta = 0.001;

bool compare(const double &x, const double &y)
{
  return fabs(x-y) < delta;
}

bool lsearch(const vector<double> &vec, const double &x)
{
  // Use std::find_if and lambda to compare
  auto it = std::find_if(vec.begin(), vec.end(), 
    [x](const double &y) { return fabs(x - y) < delta; });

  return it != vec.end();  // If found, it won't be equal to vec.end()
}
