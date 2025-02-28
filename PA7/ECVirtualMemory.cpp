//
//  ECVirtualMemory.cpp
//  
//
//  Created by Yufeng Wu on 8/30/23.
//  Implement popular page replacement algorithms

#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
#include "ECVirtualMemory.h"
#include <algorithm>
#include <limits>
using namespace std;


//*****************************************************************************
// Virtual memory: consists of memory pages and a main memory with limited capacity
// Page: represented by an integer; main memory can hold up to K pages
// Page replacement: when the main memory reaches its limit (i.e., having K pages) 
// and a new page (not currently in memory) is to be add, 
// then need to swap out one current page to make room for this new page
// This class: use OPT or LRU algorithm

// Your code here



ECVirtualMemory::ECVirtualMemory(int capacity) : capacity(capacity), numPageFaults(0) {}


void ECVirtualMemory::AccessPage(int page) 
{
    if (pageMap.find(page) != pageMap.end()) 
    {
        auto it = std::find(pageOrder.begin(), pageOrder.end(), page);
        pageOrder.erase(it);
        pageOrder.push_back(page); 
    } 
    else 
    {
        numPageFaults++;

        if (pageOrder.size() == capacity) 
        {
            int lruPage = pageOrder.front();
            pageOrder.erase(pageOrder.begin()); 
            pageMap.erase(lruPage); 
        }
        pageOrder.push_back(page);
        pageMap[page] = pageOrder.size() - 1;
    }

    pageAccessHistory.push_back(page);
}



int ECVirtualMemory::RunOpt() {
    int numPageFaultsOpt = 0;
    std::set<int> memorySet;

    for (size_t i = 0; i < pageAccessHistory.size(); ++i) 
    {
        int currentPage = pageAccessHistory[i];

        if (memorySet.find(currentPage) == memorySet.end()) 
        {
            numPageFaultsOpt++;

            if (memorySet.size() >= capacity) 
            {
                int pageToReplace = -1;
                int farthestUse = -1;

                for (int pageInMemory : memorySet) 
                {
                    int nextUse = std::numeric_limits<int>::max();
                    for (size_t j = i + 1; j < pageAccessHistory.size(); ++j) 
                    {
                        if (pageAccessHistory[j] == pageInMemory) 
                        {
                            nextUse = j;
                            break;
                        }
                    }

                    if (nextUse > farthestUse) 
                    {
                        farthestUse = nextUse;
                        pageToReplace = pageInMemory;
                    }
                }
                memorySet.erase(pageToReplace);
            }
            memorySet.insert(currentPage);
        }
    }

    return numPageFaultsOpt;
}


int ECVirtualMemory::GetNumPagesInMainMemory() const 
{
    return pageOrder.size();
}


int ECVirtualMemory::GetNumPageFaults() const 
{
    return numPageFaults;
}
