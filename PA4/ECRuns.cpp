//
//  ECRuns.cpp
//  
//
//  Created by Yufeng Wu on 08/22/23.
//
//
#include <string>
#include <iostream>
using namespace std;

// Return the number of runs, and the list of starting positions of runs in the passed in array (which you can assume it is large enough)
int ECRuns(const string &str, int *pListPositions )
{
    if (str.length() == 0)
    {
        return 0;
    }
    
    int runs = 1;
    int current = str[0];
    pListPositions[0] = 0;

    for (size_t i = 1; i < str.length(); i++)
    {
        if (str[i] == current)
        {
            continue;
        }
        else
        {
            pListPositions[runs] = i;
            runs++;
            current = str[i];
        }
    }
    return runs;
}

