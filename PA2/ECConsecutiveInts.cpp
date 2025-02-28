//
//  ECConsecutiveInts.cpp
//  
//
//  Created by Yufeng Wu on 1/15/23.
//
//

#include <iostream>
#include <string>
using namespace std;

// Test whether strInput is a string composed of consecutive and increasing integers (in decimal formats)
// Return true if yes and false otherwise (return false if there are unexpected characters)
// For example, 1234578 would return false, while 1213141516 would return true (12 13 14 15 16)
// You may assume the integers is at most 999999 and there is no any seperators between numbers
// You may also assume integers are all non-negatives

// Tip: try to use library functions instead of writing a lot of code yourself
// functions in C++ string you may find useful:
// substr: extract a substring from a string
// stoi:  convert string to integer (be careful about how to handle exception)
// and so on..

int countDigits(int num) {
    return to_string(num).length();
}

bool ECConsecutiveInts(const string &strInput)
{
  // your code  here

  // make sure it is all numbers
  for (char ch : strInput) 
  {
    if (!isdigit(static_cast<unsigned char>(ch))) 
    {
      return false;
    }
  }

  size_t maxSize = 6;
  size_t strLastIndex = strInput.length();
  for (size_t i = 1; i <= min(maxSize, strLastIndex); i++)
  {
    string firstSubString = strInput.substr(0, i);
    int currentNum = stoi(firstSubString) + 1;
    string currentString = strInput.substr(i);
    int count = 1;

    while (true)
    {
      if (currentString.length() == 0)
      {
        if (count > 1)
        {
          return true;
        }
        break;
      }
      if (countDigits(currentNum) > currentString.length())
      {
        break;
      }
      if (stoi(currentString.substr(0,countDigits(currentNum))) == currentNum)
      {
        currentString = currentString.substr(countDigits(currentNum));
        currentNum++;
        count++;
      }
      else
      {
        break;
      }
    }
  }
  return false;
}

