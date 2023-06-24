/*
    Question 4.
    Chapter 11, page 409.
    Date: 19/04/2023

    Write a program that reads strings and for each string outputs the 
    character classification of each character
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

void getType(char c)
{
    if (isspace(c))
        cout << c << " whitespace. \n";
    if (isalpha(c))
        cout << c << " is a letter. \n";
    if (isdigit(c))
        cout << c << " is a decimal digit. \n";
    if (isxdigit(c))
        cout << c << " is a hexadecimal digit. \n";
    if (isupper(c))
        cout << c << " is a uppercase letter. \n";
    if (islower(c))
        cout << c << " is a lowercase letter. \n";
    if (isalnum(c))
        cout << c << " is a letter or decimal digit. \n";
    if (iscntrl(c))
        cout << c << " is a control character. \n";
    if (ispunct(c))
        cout << c << " is not a letter, digit, whitespace, or invisible control character. \n";
    if (ispunct(c))
        cout << c << " is printable.  \n";
    if (isgraph(c))
        cout << c << " isalpha(c) or isdigit(c) or ispunct(c). \n";
    
}
int main()
{
    cout << "Enter a string: " << endl;
    string stream;
    getline(cin, stream);

    stringstream ss {stream};

    for (string s; ss >> s; ) {
        for (char c : s)
            getType(c);
    }


}