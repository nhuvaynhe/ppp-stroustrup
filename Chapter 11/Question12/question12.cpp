/*
    Question 11.
    Chapter 11, page 409.
    Date: 20/04/2023

    Reverse the order of characters in a text file.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <ctype.h>
#include <algorithm>
using namespace std;

string reverse_string(string word)
{
    string temp;

    for (int i=word.size() -1; i >= 0; --i)
        temp += word[i];

    return temp;
}

int main()
{
    fstream readIn {"text.txt"};

    string temp;
    while (readIn >> temp)
    {
        stringstream ss {temp};

        for (string s; ss >> s; )
        cout << reverse_string(s) << endl;
    }

   
    
}