#include <iostream>

// Function to reverse a string using pointers
void reverseString(char* str) {
    // Pointers to the beginning and end of the string
    char* start = str;
    char* end = str;

    // put your code here
    while (*end != '\0') {
        end++;
    }
    end--;
    while (start < end)
    {
        char temp = *end;
        *end = *start;
        *start = temp;
        start++;
        end--;
    }
    
}

int main() {
    char str[] = "oliver";

    std::cout << "Original string: " << str << std::endl;

    // Reverse the string
    reverseString(str);
    std::cout << "Reversed string: " << str << std::endl;

    return 0;
}
