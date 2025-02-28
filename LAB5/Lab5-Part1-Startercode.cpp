#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric> // For std::accumulate

// TODO: Convert this function to work with any STL container (like list, set, etc.) using templates
template <typename container>
void printVector(const container& vec) {
    for (auto val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    // TODO: Change the STL container from std::vector to std::list
    std::list<int> numbers = {5, 12, 9, 3, 7};

    // # TODO - Modify the below code to sort this  using a built in list function.
    numbers.sort();
    std::cout << "Sorted Vector: ";
    printVector(numbers);

    // TODO: Reverse the container and print the result using std::reverse
    numbers.reverse();
    std::cout << "Reversed Vector: ";
    printVector(numbers);

    // Find an element
    auto it = std::find(numbers.begin(), numbers.end(), 9);
    if (it != numbers.end()) {
        std::cout << "Found 9 in the vector!" << std::endl;
    } else {
        std::cout << "9 not found in the vector!" << std::endl;
    }

    // TODO: Use std::accumulate to calculate the sum of all elements and print the sum
    std::cout << "Accumulated Vector: " << std::accumulate(numbers.begin(), numbers.end(), 0) << std::endl;

    // TODO: Use std::count to count how many times the number 9 appears in the container, print out the number of times. 
    std::cout << "Number of times 9 is in list: " << std::accumulate(numbers.begin(), numbers.end(), 9) << std::endl;
    return 0;
}


