#include "Bin_Number_Starter_Code_Part1.h"

//Task 2 part a ...Below function needs to be uncommented


// BinaryNumber BinaryNumber :: operator+(const BinaryNumber& val2) const {

//     std::vector<int> result;
//     int carry = 0;

//     size_t maxSize = std::max(bits.size(), val2.bits.size());
//     result.reserve(maxSize + 1); // +1 for possible carry

//     for (size_t i = 0; i < maxSize; ++i) {
//         int bitA = (i < bits.size()) ? bits[bits.size() - 1 - i] : 0;
//         int bitB = (i < val2.bits.size()) ? val2.bits[val2.bits.size() - 1 - i] : 0;

//         int sum = bitA + bitB + carry; // Add bits and carry
//         result.push_back(sum % 2); // Result bit is sum modulo 2
//         carry = sum / 2; // New carry is sum divided by 2
//     }

//     if (carry) {
//         result.push_back(carry); // Add final carry if necessary
//     }

//     std::reverse(result.begin(), result.end()); // Reverse to correct order
//     return BinaryNumber(result); // Create a new BinaryNumber from the result vector
// }

//Task 2 part a ...Below function needs to be commented to make sure that sum3 in main function fails

BinaryNumber operator+(const BinaryNumber& val1, const BinaryNumber& val2) {
    std::vector<int> result;
    int carry = 0;

    size_t maxSize = std::max(val1.bits.size(), val2.bits.size());
    result.reserve(maxSize + 1); // +1 for possible carry

    for (size_t i = 0; i < maxSize; ++i) {
        int bitA = (i < val1.bits.size()) ? val1.bits[val1.bits.size() - 1 - i] : 0;
        int bitB = (i < val2.bits.size()) ? val2.bits[val2.bits.size() - 1 - i] : 0;

        int sum = bitA + bitB + carry; // Add bits and carry
        result.push_back(sum % 2); // Result bit is sum modulo 2
        carry = sum / 2; // New carry is sum divided by 2
    }

    if (carry) {
        result.push_back(carry); // Add final carry if necessary
    }

    std::reverse(result.begin(), result.end()); // Reverse to correct order
    return BinaryNumber(result); // Create a new BinaryNumber from the result vector
}

// Multiplication operator overload (friend function)
//Task 2 Part b Complete the Multiplication function and make sure the multiplication in main function returns correct results
BinaryNumber operator*(const BinaryNumber& val1, const BinaryNumber& val2) 
{
   // Return the result of multiplication
    BinaryNumber result("0");

    for (size_t i = 0; i < val2.bits.size(); i++)
    {
        if (val2.bits[val2.bits.size()-i-1] == 0)
        {
            continue;
        }
        else
        {
            BinaryNumber temp = val1;
            for (size_t j = 0; j < i; j++)
            {
                temp.bits.push_back(0);
            }
            result = result + temp;
        }
    }
    return result;
}


// Example usage
int main() {
    try {
        BinaryNumber bin1("1101");  // Binary representation of 13
        std::cout << "Binary 1: ";
        bin1.print();                 // Output: 1101

        BinaryNumber bin2("101");    // Binary representation of 5
        std::cout << "Binary 2: ";
        bin2.print();                 // Output: 101

        BinaryNumber sum = bin1 + bin2; // Addition
        std::cout << "Sum: ";
        sum.print();                   // Output: 10000 (18 in decimal)

        BinaryNumber product = bin1 * bin2; // Multiplication
        std::cout << "Product: ";
        product.print();               // Output: 111101 (65 in decimal)

        // try a different way of doing addition
        std::string str1 = "101";
        // this invokes the overload + operator inside the class, and it works
        BinaryNumber sum2 = bin2 + str1;
        std::cout << "Sum2: ";
        sum2.print();

	// but if you swap the order, oops! So why the commutative law of summation fails to hold here?
        BinaryNumber sum3 = str1 + bin2;
        std::cout << "Sum3: ";
        sum3.print();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
