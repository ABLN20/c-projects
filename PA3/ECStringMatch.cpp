//
//  ECStringMatch.cpp
//  
//
//  Created by Yufeng Wu on 6/16/24.
//

#include "ECStringMatch.h"
#include <iostream>

// Brute-force matching: given text strText and pattern strPattern
// return true if strPattern is an exact substring of strText, and false otherwise
bool ECStrMatchBruteForce(const string &strText, const string &strPattern)
{
    // your code here
    if (strPattern.length() > strText.length())
    {
        return false;
    }
    for (size_t i = 0; i <= (strText.length() - strPattern.length()) ; i++)
    {
        if (strText.substr(i,strPattern.length()) == strPattern)
        {
            return true;
        }
    }
    return false;   
}

// C++ library based striing matching: simply call C++ string's find function
// This function is given; DON'T CHANGE IT
bool ECStrMatchBuiltIn(const string &strText, const string &strPattern)
{
    return strText.find(strPattern) != string::npos;
}

// Implement a slightly more complicated algorithm based on nummerical computation
// given text strText and pattern strPattern, an integer d, a prime number q 
// return true if strPattern is an exact substring of strText, and false otherwise
// The algorithm would work as follows:
// For each position i of strText, convert the subtring strText[i..i+length(strPattern)]
// to an integer (where d is the base of this integer) and then take modulo of q
// We also convert strPattern to an integer P in the same way. Then we simply compare 
// the integers constructed from strText. The key is, if the text integer doesn't match
// P, then the corresponding substring cannot match strPattern. Only when 
// P is equal to the text integer, we would conduct a letter-by-letter check to see if
// there is indeed a match at this position 
// Be careful: you need to implement the above procedure efficiently; 
// a naive implementation would be even slower than the brute-force!
// Be sure to look for ways to make your code more efficient.

bool ECStrMatchNumCompare(const string &strText, const string &strPattern, int d, int q) {
    int n = strText.size();
    int m = strPattern.size();

    if (m > n) {
        return false; // Pattern is longer than text
    }

    // Compute the hash value for the pattern
    long long patternHash = 0;
    for (char c : strPattern) {
        patternHash = (d * patternHash + c) % q;
    }

    // Compute the hash value for the first window of the text
    long long textHash = 0;
    for (int i = 0; i < m; ++i) {
        textHash = (d * textHash + strText[i]) % q;
    }

    // Precompute d^(m-1) % q for rolling hash
    long long d_m_minus_1 = 1;
    for (int i = 0; i < m - 1; ++i) {
        d_m_minus_1 = (d_m_minus_1 * d) % q;
    }

    // Rolling hash to find the pattern
    for (int i = 0; i <= n - m; ++i) {
        // Compare hashes
        if (textHash == patternHash) {
            // Verify by direct comparison
            if (strText.substr(i, m) == strPattern) {
                return true;
            }
        }

        // Compute hash for the next window
        if (i < n - m) {
            textHash = (d * (textHash - strText[i] * d_m_minus_1) + strText[i + m]) % q;
            if (textHash < 0) { // Handle negative values
                textHash += q;
            }
        }
    }

    return false;
}
