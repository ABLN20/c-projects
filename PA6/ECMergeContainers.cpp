// Created by Y. Wu, Jan 31, 2023
// Merge lists (of any STL container type) into a single sorted list (of any STL container type)
// Duplicates allowed unless the output doesn't take duplicates (e.g., a map)
// Note: you should make your code as flexible as possible: you should allow all kinds of outputs: vector, set, etc 
// Make your code short: at most 10 lines of code (LOC) 
#include <algorithm>
// now defiine ECMergeContainers ...

template <typename inConTemplate, typename outConTemplate>
void ECMergeContainers(const inConTemplate& listIn, outConTemplate& listOut)
{
    for (const auto& cont: listIn)
    {
        listOut.insert(listOut.end(), cont.begin(), cont.end());
    }
    std::sort(listOut.begin(), listOut.end());
}