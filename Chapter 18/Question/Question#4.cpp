/*
    Question #4.
    Chapter 18, page 665.
    Date: 08/05/2023.

        Consider what happens if you give strdup(), findx(), and strcmp() an argu-
    ment that is not a C-style string. Try it! First figure out how to get a char* 
    that doesn’t point to a zero-terminated array of characters and then use 
    it (never do this in real — non-experimental — code; it can create havoc). 
    Try it with free-store-allocated and stack-allocated “fake C-style strings.” 
    If the results still look reasonable, turn off debug mode. Redesign and 
    re-implement those three functions so that they take another argument 
    giving the maximum number of elements allowed in argument strings.
*/

#include <iostream>
using namespace std;

