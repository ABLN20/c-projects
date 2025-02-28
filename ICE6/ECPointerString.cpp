#include "ECPointerString.h"
using namespace std;


ECStringPtr :: ECStringPtr()
{
    ptr = nullptr;
}

ECStringPtr :: ECStringPtr(const string &strInit)
{
    ptr = new string(strInit);
}

ECStringPtr :: ECStringPtr(const ECStringPtr &rhs) {
    if (rhs.ptr != nullptr) 
    {
        ptr = new string(*rhs.ptr);
    }
    else 
    {
        ptr = nullptr;
    }
}

ECStringPtr :: ECStringPtr(ECStringPtr &&rhs)
{
    ptr = rhs.ptr;
    rhs.ptr = nullptr;
}

ECStringPtr :: ~ECStringPtr()
{
    delete ptr;
}

ECStringPtr &ECStringPtr::operator=(const ECStringPtr &rhs) {
    if (this != &rhs) 
    {
        delete ptr; 
        if (ptr != nullptr)
        {
            ptr = new string(*rhs.ptr);
        }
        else 
        {
            ptr = nullptr;
        }
    }
    return *this; 
}

void ECStringPtr::SetString(const std::string &strToSet) {
    delete ptr;
    ptr = new string(strToSet);
}

const string *ECStringPtr::GetPtr() const {
    return ptr;  
}

ECStringPtr ECStringPtr::Duplicate() const {
    if (ptr != nullptr) 
    {
        return ECStringPtr(*ptr + *ptr);
    } 
    else 
    {
        return ECStringPtr();
    }
}
