/*
    Question 5.
    Chapter 17, page 624.
    Write a function, char* findx(const char* s, const char* x), that finds the 
    first occurrence of the C-style string x in s.
*/

#include <iostream> 
#include <cstring>
using namespace std;

const char* find(const char* s, const char* x)
{
    int s_len = strlen(s);
    int x_len = strlen(x);

    for (int i=0; i < s_len - x_len; ++i) 
    // the condition "i< s_len - x_len" limits the loop to search, useful for strncmp
    {
        if (strncmp(s +i, x, x_len) == 0) return s + i;
        /*
            with `x`. The function call `strncmp(s + i, x, x_len)` 
            compares the first `x_len` characters of the substring of `s` 
            starting at index `i` with the characters of `x`.
        */
    }

    return nullptr;
}

int main()
{
    char str[] = "It's a rainy day, isn't it?";
    char pattern[] = "day";

    const char* result = find(str, pattern);

    if (result == nullptr) {
        cout << "There is no match!" << endl;
    }
    else {
        cout << "Pattern found at " << (int) (result - str) << endl;
    }

    /*
        The expression `(result - str)` calculates the difference between the 
        memory addresses pointed to by `result` and `str`. Since `result` points 
        to the start of the matched pattern `x`, and `str` points to the start of the `s` string, 
        the calculation `(result - str)` will give the number of bytes between the two pointers.
    */
}