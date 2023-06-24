/*
    Question #10.
    Chapter 18, page 665.
    Date: 08/05/2023.

    Look at the “array solution” to the palindrome problem in §18.7.2. Fix it 
    to deal with long strings by (a) reporting if an input string was too long 
    and (b) allowing an arbitrarily long string. Comment on the complexity 
    of the two versions.
*/

#include <iostream>
#include <cstring>
using namespace std;

int arr_strlen(const char* ch)
{
    int n=0;
    while (ch[n]) ++n;

    return n;
}

bool is_palindrome(const char s[], int n)
{   
    int first = 0;
    int last = n-1;
    while (first < last) {
        if (s[first] != s[last]) return false;

        ++first;
        --last;
    }

    return true;
}

istream& read_word(istream& is, char* buffer, int max)
{
    is >> buffer;

    if (arr_strlen(buffer) > max) {
        cerr << "Your input is exceed max value" << endl;
        
        is.clear(); // clear error flags on stream
        is.sync();  // synchronize input stream
        is.ignore(999999, '\n'); // ignore remaining characters up to newline character
    }


    return is;
    
}

int main()
{
    constexpr int max = 10;
    for (char s[max]; read_word(cin, s, max); ){
        cout << s << " is";
        if (!is_palindrome(s, strlen(s))) cout << " not";
        cout << " a palindrome\n";
    }
}