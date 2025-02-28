#include <vector>
#include <set>
#include <iostream>
using namespace std;

// I want to have a generic function that can work with any types of numbers 
// AND any type of container. Is this possible?
template <class T, template <class...> class Container>
T ECSumList(const Container<T> &listNums)
{
  // your code goes here ...
  T total = 0;
  for (T i: listNums)
  {
    total += i;
  }
  return total;
}

