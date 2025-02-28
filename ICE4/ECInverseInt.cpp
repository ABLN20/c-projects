#include <string>
#include <algorithm> 
using namespace std;
// define a functionc called ECInverseInt that takes a single parameter (a string) and return a string as its inversed integer
// Your code here
string ECInverseInt(const string& input)
{
    string res = input;
    reverse(res.begin(), res.end());
    int converted = stoi(res);
    res = to_string(converted);
    return res;
}