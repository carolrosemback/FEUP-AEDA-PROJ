#include "split.h"

vector<string> split(string str, string delimiter)
{
    vector<string> result;
    size_t pos = 0;
    string token;
    pos = str.find(delimiter);
    while (pos != str.npos)
    {
        token = str.substr(0, pos);
        result.push_back(token);
        str.erase(0, pos + delimiter.length());
        pos = str.find(delimiter);
    }
    result.push_back(str);
    return result;
}