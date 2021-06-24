#include "Utils.h"
using namespace std;

void Tokenize(const string& line, vector<string>& arguments)
{
    const char* str = line.c_str();

    do
    {
        const char* begin = str;

        while (*str != ' ' && *str)
            str++;

        arguments.push_back(string(begin, str));
    } while (0 != *str++);
}