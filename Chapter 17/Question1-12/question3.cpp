/*
    Question 3.
    Chapter 17, page 624.
    Write a function, void to_lower(char* s), that replaces all uppercase characters 
    in the C-style string s with their lowercase equivalents. 
*/

#include <iostream> 
using namespace std;

void to_lower(char* s)
{   
    while (*s) {
        if (*s >= 'A' && *s <= 'Z')
            *s += ('a' - 'A');

        ++s;
    }
}
//-------------------------------------------------------------------------- 
int main()
{
    char str[] = "HeLLo WoRlD";

    to_lower(str);
    cout << str;
}