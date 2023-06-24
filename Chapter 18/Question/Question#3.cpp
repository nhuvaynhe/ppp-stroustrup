/*
    Question #3.
    Chapter 18, page 664.
    Date: 08/05/2023.

    Write a function, int strcmp(const char* s1, const char* s2), that compares 
    C-style strings. Let it return a negative number if s1 is lexicographically 
    before s2, zero if s1 equals s2, and a positive number if s1 is lexicograph-
    ically after s2. Do not use any standard library functions. Do not use 
    subscripting; use the dereference operator * instead.
*/

#include <iostream>
using namespace std;

int strlen(const char* ch)
{
    int n=0;
    while (ch[n]) ++n;

    return n;
}

int strcmp(const char* s1, const char* s2)
{
    int sz_1 = strlen(s1);
    int sz_2 = strlen(s2);

    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 > *s2) return 1;
        if (*s1 < *s2) return -1;

        *s1++;
        *s2++;
    }

    if (sz_1 > sz_2) return 1;
    if (sz_1 < sz_2) return -1;

    return 0;
}

int main()
{
    char ch1[] = "Nguyen Ngoc Dai";
    char ch2[] = "Nguyen Ngoc";

    cout << strcmp(ch2, ch1);
}