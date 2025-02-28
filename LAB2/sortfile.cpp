#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void sortIntegersInFile(const std::string& inputFile, const std::string& outputFile) {
    // Vector to store the integers
    std::vector<int> numbers;

    // Open input file for reading
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Error opening input file: " << inputFile << std::endl;
        return;
    }

    // Read integers from file and store in the vector
    int num;
    while (inFile >> num) {
        numbers.push_back(num);
    }

    // Close the input file
    inFile.close();

    // Sort the integers using the standard sort function
    std::sort(numbers.begin(), numbers.end());

    // Open output file for writing
    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Error opening output file: " << outputFile << std::endl;
        return;
    }

    // Write the sorted integers to the output file
    for (const int& n : numbers) {
        outFile << n << std::endl;
    }

    // Close the output file
    outFile.close();

    std::cout << "Sorting completed successfully. Check the output file: " << outputFile << std::endl;
}

int main() {
    // Call the function with file names
    sortIntegersInFile("input.txt", "output.txt");

    return 0;
}