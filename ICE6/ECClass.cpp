#include "ECClass.h"
#include <vector>
#include <string>
using namespace std;

// Class for class
ECClass :: ECClass()
{
}

void ECClass :: AddStudent( const ECStudent &s)
{
  // your code
  double studentAve = s.GetAve();

  for (size_t i = 0; i < listStu.size(); i++)
  {
    if (listStu[i].GetAve() < studentAve)
    {
      listStu.insert(listStu.begin() + i, s);
      return;
    }
  }
  listStu.push_back(s);
}

double ECClass :: GetAveMedian() const
{
  if (listStu.size() % 2 == 1)
  {
    return listStu[listStu.size() / 2].GetAve();
  }
  else 
  {
    return (listStu[listStu.size() / 2].GetAve() + listStu[(listStu.size() - 1) / 2].GetAve()) / 2;
  }
}

std::string ECClass :: GetRankedStudentName(int n) const
{
  // your code
  if (n > listStu.size() - 1 || n < 0)
  {
    return "";
  }
  return listStu[n].GetName();
}

