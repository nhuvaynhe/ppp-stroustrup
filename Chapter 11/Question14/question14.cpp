/*
    Question 11.
    Chapter 11, page 409.
    Date: 20/04/2023

    Write a program that reads a text file and writes out how many characters 
    of each character classification (§11.6) are in the file.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <ctype.h>
#include <algorithm>
using namespace std;

void getType(string s)
{
    int whitespace(0), letter(0), dec_digit(0), hex_digit(0), 
        upper(0), lower(0), alnum(0), cntrl(0), punct(0);

    for (char c : s) {
        if (isspace(c)) ++whitespace;
        if (isalpha(c)) ++letter;
        if (isdigit(c)) ++dec_digit;
        if (isxdigit(c)) ++hex_digit;
        if (isupper(c)) ++upper;
        if (islower(c)) ++lower;
        if (isalnum(c)) ++alnum;
        if (iscntrl(c)) ++cntrl;
        if (ispunct(c)) ++punct;
    }
    
    
    cout << "Types of characters in string:" << endl;
	cout << "Spaces: " << whitespace << endl;
	cout << "Letters: " << letter << endl;
	cout << "Decimal Digits: " << dec_digit << endl;
	cout << "Hexadecimal Digits: " << hex_digit << endl;
	cout << "Upper Case Characters: " << upper << endl;
	cout << "Lower Case Characters: " << lower << endl;
	cout << "Control Characters: " << cntrl << endl;
	cout << "Punctuation Characters: " << punct << endl;
}

int main()
{
    cout << "Enter a string: " << endl;
    string stream;
    cin >> stream;

    getType(stream);


}