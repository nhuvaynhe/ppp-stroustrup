/*
    Question #5.
    Chapter 18, page 665.
    Date: 08/05/2023.

    Write  versions  of  the  cat_dot()s  from  the  previous  exercises  to  take 
    C-style strings as arguments and return a free-store-allocated C-style string 
    as the result. Do not use standard library functions or types in the im-
    plementation. Test these functions with several strings. Be sure to free 
    (using delete) all the memory you allocated from free store (using new). 
    Compare the effort involved in this exercise with the effort involved for 
    exercises 5 and 6.
*/

#include <iostream>
using namespace std;

int strlen(const char* ch)
{
    int n=0;
    while (ch[n]) ++n;

    return n;
}

char* cat_dot(const char* s1, const char* s2, const char* arg)
{
    int sz_1 = strlen(s1);
    int sz_2 = strlen(s2);
    int sz_arg = strlen(arg);

    int sz = sz_1 + sz_2 +sz_arg;

    char* arr_copied = new char[sz];
    char* first_block = arr_copied;

    for (int i=0; i<sz_1; ++i) 
    {   
        *arr_copied = *s1;

        *s1++;
        *arr_copied++;
    }


    for (int i = 0; i < sz_arg; ++i)
    {   
        *arr_copied = *arg;

        *arg++;
        *arr_copied++;
    }

    for (int i = 0; i < sz_2; ++i)      
    {   
        *arr_copied = *s2;

        *s2++;
        *arr_copied++;

    }

    return first_block;
}

int main()
{
    char prev[] = "Dai";
    char succ[] = "Ngoc";
    char seper[] = "-->";
    int sz = strlen(prev) + strlen(succ) + strlen(seper);

    char* ch_copied = cat_dot(prev, succ, seper);

    for (int i=0; i<sz; ++i)
    {
        cout << *ch_copied;
        ++ch_copied;
    }

    delete[] ch_copied;
}