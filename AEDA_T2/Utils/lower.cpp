#include "lower.h"

string lower(string s)
{
    string r;
    for(char c : s)
    {
        r += tolower(c);
    }
    return r;
}