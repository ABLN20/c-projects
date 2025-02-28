#include <iostream>

// C-style casting (Unsafe)
// Create a function which prints an unsafe cast of a double to an int in C-style
void unsafeCastExample() {

  // Code Here
  double j = 3.5543;
  int k = (int)j;
  std::cout << k << "\n";
}

// C++-style casting (Safe)
// Create a function which that shows an unsafe cast of a double to an int in C++-style
// The code should not run due to a compilation error
/*
void safeCastExample() {
    double value = 3.14;
    
    // This will cause a compilation error because C++ doesn't allow implicit narrowing conversion from double to int.
    int intValue = value;
}
*/


// Correct C++-style casting (Safe)
// Create a function correctly casting a double to an integer in C++-style
void correctCastExample() {

  // Code here
    double value = 3.14;
    int intValue = static_cast<int>(value);
    std::cout << "Correctly casted int value: " << intValue << std::endl;
}

int main() {
  unsafeCastExample();
  correctCastExample();
  return 0;
}