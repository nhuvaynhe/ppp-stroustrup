/*
    Try this #1.
    Chapter 17, page 591.
    Date: 23/04/2023
*/

#include "std_lib_facilities.h"

void sizes(char ch, int i, double d, bool b, int* p)
{
    cout <<  "the size of char is " << sizeof(char) << ' ' << sizeof(ch) << '\n';
    cout <<  "the size of int is " << sizeof(int) << ' ' << sizeof(i) << '\n';
    cout <<  "the size of double is " << sizeof(double) << ' ' << sizeof(d) << '\n';
    cout <<  "the size of bool is " << sizeof(bool) << ' ' << sizeof(b) << '\n';
    cout <<  "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << '\n';
}

int main()
{
    char ch = 'A';
    int i = 16;
    int* p = &i;
    bool b = true;
    double d = 16.06;

    sizes(ch, i, d, b, p);
}