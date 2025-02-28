#include "ECTime.h"

ECTime::ECTime(int h, int m, int s)
{
    hour = h;
    min = m;
    sec = s;

    if (sec >= 60) 
    {
        min += sec / 60;
        sec %= 60;
    }

    if (min >= 60) 
    {
        hour += min / 60;
        min %= 60;
    }
}

ECTime::~ECTime()
{
}

void ECTime::GetTime(int &h, int &m, int &s) const 
{
    h = hour;
    m = min;
    s = sec;
}


ECTime ECTime::operator+(const ECTime &tmToAdd) 
{
    int newSec = sec + tmToAdd.sec;
    int newMin = min + tmToAdd.min;
    int newHour = hour + tmToAdd.hour;
    return ECTime(newHour, newMin, newSec);
}