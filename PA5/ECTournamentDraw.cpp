//
//  ECTournamentDraw.cpp
//  
//
//  Created by Yufeng Wu on 8/4/24.
//  


#include "ECTournamentDraw.h"
using namespace std;

//*****************************************************************************
// Please note:
// (1) Try to avoid long functions
// (2) Try to reduce nested loops; only use double loops when necessary; avoid triple loops
// (3) Try to reduce conditional statements
// My code has 1 double loop, 5 single loops, 4 if-conditional, longest function has 20 LOC, total LOC is 132 (incl. comments). 
// Try to write your code that has similar complexity

// Tips
// Consider using STL algorithms such as std::copy and inserters to remove explicity loops


//*****************************************************************************
// You may define non-interface functions here so to organize the code better
bool allowDupRanks = false;
bool allowMorePlayersPerCountry = false;
bool noCheckFirstTwoRounds = false;
bool noSeeds = false;

// Function to check for duplicate ranks
bool CheckDuplicateRanks(const vector<int>& vecPlayersRank) 
{
    set<int> ranks(vecPlayersRank.begin(), vecPlayersRank.end());
    return ranks.size() == vecPlayersRank.size();
}

// Function to check the limit of players per country
bool CheckCountryPlayerLimit(const vector<int>& vecPlayersCountries) 
{
    map<int, int> countryCount;
    for (int country : vecPlayersCountries) 
    {
        countryCount[country]++;
        if (countryCount[country] >= 3) 
        {
            return false;
        }
    }
    return true;
}

bool CheckFirstTwoRounds(const vector<int>& vecPlayersCountries) 
{
    vector<int>::const_iterator startIter = vecPlayersCountries.begin();
    vector<int>::const_iterator endIter = vecPlayersCountries.begin() + 4;
    while (endIter != vecPlayersCountries.end())
    {
        set<int> currentBracket(startIter, endIter);
        if (currentBracket.size() != 4)
        {
            return false;
        }
        startIter += 4;
        endIter += 4;
    }
    return true;
}

bool noSeedsCheck(const vector<int>& vecPlayersRank) 
{
    vector<int> sortedPlayersRank = vecPlayersRank;
    sort(sortedPlayersRank.begin(), sortedPlayersRank.end());
    int first = sortedPlayersRank[0];
    int second = sortedPlayersRank[1];
    int mid = vecPlayersRank.size() / 2;

    int firstsInFirstHalf = count(vecPlayersRank.begin(), vecPlayersRank.begin() + mid, first);
    if (firstsInFirstHalf >= 2)
    {
        return false;
    }
    int secondsInFirstHalf = count(vecPlayersRank.begin(), vecPlayersRank.begin() + mid, second);
    if (firstsInFirstHalf + secondsInFirstHalf >= 2)
    {
        return false;
    }

    int firstsInSecondHalf = count(vecPlayersRank.begin() + mid, vecPlayersRank.end(), first);
    if (firstsInSecondHalf >= 2)
    {
        return false;
    }
    int secondsInSecondHalf = count(vecPlayersRank.begin() + mid, vecPlayersRank.end(), second);
    if (firstsInSecondHalf + secondsInSecondHalf >= 2)
    {
        return false;
    }
    return true;
}

//*****************************************************************************
// Purpose of this assignment: get familiar with STL
// Containers: vector, set, map
// Algorithms: sort

//*****************************************************************************
// Interface functions

// checking whether a given tournament draw is valid or not
// Input: two STL vectors: (i) vecPlayersRank[i]: rank (1 being highest) of the i-th player
//   in the draw, (ii) vecPlayersCountries[i]: country (coded as integers) of the i-th player in the darw
//   you can assume the two vectors are of the same length; you can also assume the number of players
//   (size of vectors) is a power of 2, and has at least 16 players
// Output: true if the draw is valid wrt a set of pre-defined rules, false otherwise
// Note: by default, all four rules are to checked, unless turned off by the caller
bool ECCheckTournamentDraw(const vector<int> &vecPlayersRank, const vector<int> &vecPlayersCountries)
{
    if (!allowDupRanks && !CheckDuplicateRanks(vecPlayersRank)) {
        return false;
    }

    if (!allowMorePlayersPerCountry && !CheckCountryPlayerLimit(vecPlayersCountries)) {
        return false;
    }

    if (!noCheckFirstTwoRounds && !CheckFirstTwoRounds(vecPlayersCountries)) {
        return false;
    }

    if (!noSeeds && !noSeedsCheck(vecPlayersRank)) {
        return false;
    }

    return true;
}
// configure checking: allow ties in ranking
void ECAllowDupRanks()
{
    allowDupRanks = true;
}

// configure checking: allow more than 2 players per country
void ECAllowMorePlayersPerCountry()
{
    allowMorePlayersPerCountry = true;
}

// configure checking: allow players from the same country to play in any round
void ECNoCheckFirstTwoRounds()
{
    noCheckFirstTwoRounds = true;
}

// configure checking: no checking of the distribution of seeded players
void ECNoSeedsCheck()
{
    noSeeds = true;
}