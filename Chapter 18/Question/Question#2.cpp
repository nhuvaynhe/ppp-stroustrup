/*
    Question #2.
    Chapter 18, page 664.
    Date: 08/05/2023.

    Write a function, char* findx(const char* s, const char* x), that finds the 
    first occurrence of the C-style string x in s. Do not use any standard li-
    brary functions. Do not use subscripting; use the dereference operator * 
    instead.
*/

#include <iostream>
using namespace std;

char* findx( char* s,  char* x)
{
    int index = 0;

    while (*s != '\0')
    {
        if (*s == *x) {
            cout << "Found " << *x << " at index [" << index << "]" << endl;
            return &s[index];
        }

        ++index;
        *s++;
    }

    return nullptr;
}

int main()
{
    char ch[] = "Nguyen Ngoc Dai";

    char key = 'c';

    findx(ch, &key);
}
