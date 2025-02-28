//
//  RemoveDupPointers.cpp
//  
//
//  Created by Yufeng Wu on 1/18/21.
//
//

#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

void RemoveDupPointers(vector<string *> &arrayPtrs)
{
    set<string> uniqueStrings;
    
    auto current = arrayPtrs.begin();
    
    while (current != arrayPtrs.end())
    {
        string *strPtr = *current;

        if (uniqueStrings.find(*strPtr) != uniqueStrings.end())
        {
            current = arrayPtrs.erase(current);
        }
        else
        {
            uniqueStrings.insert(*strPtr);
            current++;
        }
    }
}
