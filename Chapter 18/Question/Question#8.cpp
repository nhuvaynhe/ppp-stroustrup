/*
    Question #8.
    Chapter 18, page 665.
    Date: 08/05/2023.

    Rewrite all the functions in §18.7 to use the approach of making a back-
    ward copy of the string and then comparing; for example, take "home", 
    generate  "emoh",  and  compare  those  two  strings  to  see  that  they  are 
    different, so home isn’t a palindrome.
*/

#include <iostream>
using namespace std;

bool isPalindrome(const string& s)
{
    int first = 0;
    int last = s.length() -1;

    string temp;
    while(last >= 0) {
        temp += s[last];
        --last;
    }

    if (temp != s) return false;
    return true;
}
int main()
{
    string test = "opopo";

    if (isPalindrome(test)) 
        cout << "Palindrome";
    else  
        cout << "Not palindrome";
}