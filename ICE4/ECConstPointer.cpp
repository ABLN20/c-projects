#include <iostream>

void ECSumArray(const int *listNums, int size)
{
  // You need to loop through the array using pointer. How to define this pointer?
  int total = 0;
  for (size_t i = 0; i < size; i++)
  {
    total += *(listNums + i);
  }
  std::cout << total << "\n";
}

int main()
{
  int array[] = {1,2,3,5};
  ECSumArray(array, 4);
  return 0;
}
