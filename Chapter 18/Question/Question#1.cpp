/*
    Question #1.
    Chapter 18, page 664.
    Date: 08/05/2023.

    Write a function, char* strdup(const char*), that copies a C-style string 
    into memory it allocates on the free store. Do not use any standard li-
    brary functions. Do not use subscripting; use the dereference operator * 
    instead.
*/

#include <iostream>
using namespace std;

int strlen(const char* ch)
{
    int n=0;
    while (ch[n]) ++n;

    return n;
}

char* strdup(const char* ch)
{   
    int sz = strlen(ch);

    char* arr_copied = new char[sz];

    for (int i=0; i<sz; ++i)
    {   
        *arr_copied = *ch;

        *ch++;
        *arr_copied++;
    }

    return arr_copied - sz;
}

int main()
{
    char ch[] = "Nguyen Ngoc Dai";

    char* ch_copied = strdup(ch);

    for (int i=0; i<strlen(ch); ++i)
    {
        cout << *ch_copied;
        ++ch_copied;
    }

}
