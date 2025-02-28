#include <iostream>
using namespace std;

// complete the definition of the sorting function ...
void ECSortFP(int *listNumbers, int size, bool (*OrderingFunction)(int,int))
{
  // your code here
}

bool IsEarlier(int x, int y)
{
  // prefer smaller item earlier (standard sorting)
}
bool IsEarlierReverse(int x, int y)
{
  // prefer larger one earlier
}
bool IsEarlierParity(int x, int y)
{
  // put even number earlier; if both are even or both are odd, sort by their values
}

bool IsEarlierPrime(int x, int y)
{
  // put prime numbers earlier, if both are prime or both are not prime, sort by their values
}

// int main()
// {
//   int arr[] = {1,3,2,4};
//   ECSortFP(arr, 4, ???);

//   // print it out
//   for(int i=0; i<4; ++i)
//   {
//     cout << arr[i] << " ";
//   }
//   cout << endl;
// }

