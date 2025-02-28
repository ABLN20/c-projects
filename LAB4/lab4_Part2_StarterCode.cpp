#include <iostream>
#include <string>
#include <chrono>


// Uncaught exception vs segmentation fault
// Create a function which shows an exception throw using the built in function at() for a string 
// vs an out of bounds which may cause a segmentation fault
void exceptionVsSegmentationFault() {
    std::cout << "Uncaught Exception vs Segmentation Fault: " << std::endl;
    std::string str = "Hello World";

    try {
        std::cout << "Accessing out of bounds with at(): " << str.at(20) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "Accessing out of bounds with []: " << str[20] << std::endl;
}

// The performance of std::string::at() vs []
// Create a function to compare the time difference of using [] vs at() with a large string when accessing the same index N times
void comparePerformance() {
    std::cout << "\nPerformance Comparison: " << std::endl;

    const size_t N = 100000000;
    std::string str = "abcdefghijklmnopqrstuvwxyz";

    auto start_at = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < N; ++i) {
        char ch = str.at(10);
    }
    auto end_at = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_at = end_at - start_at;
    std::cout << "Time for std::string::at(): " << time_at.count() << " seconds" << std::endl;

    // Measure time for []
    auto start_bracket = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < N; ++i) {
        char ch = str[10];
    }
    auto end_bracket = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_bracket = end_bracket - start_bracket;
    std::cout << "Time for [] operator: " << time_bracket.count() << " seconds" << std::endl;
}



// compile with and without the "-02" flag (optimization flag) and see the difference bewtween them
// e.g. w/ the flag: "g++ -O2 lab4_Part2_Solution.cpp -o output" 
int main() {
    exceptionVsSegmentationFault();
    comparePerformance();
    return 0;
}