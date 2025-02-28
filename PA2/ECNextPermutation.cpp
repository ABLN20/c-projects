#include <string>
#include <algorithm>

// You are given a list of integers listNumbers and its size
// These numbers are the permutaiton of the first sz integers, starting from 1
// After the function returns, listNumbers would contain the next permutation
// For example, if the list is 1 3 4 2  ==> 1 4 2 3
// Note: you don't need to check whether the given input is indeed a permutation
// That is, listNumbers always contains a valid permutation
void ECNextPermutation(int *listNumbers, int sz)
{
    int i = sz - 2;

    // Find the first decreasing element from the end
    while (i >= 0 && listNumbers[i] >= listNumbers[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Find the smallest element larger than listNumbers[i] from the end
        int j = sz - 1;
        while (listNumbers[j] <= listNumbers[i]) {
            j--;
        }
        // Swap the elements at i and j
        std::swap(listNumbers[i], listNumbers[j]);
    }

    // Reverse the elements from i+1 to the end
    std::reverse(listNumbers + i + 1, listNumbers + sz);
}