/*
    Question 6.
    Chapter 11, page 409.
    Date: 19/04/2023

    Write a program that replaces punctuation with whitespace. 
    Consider those punctuation characters: 
        . (dot)
        ; (semicolon) 
        , (comma)
        ? (question mark)
        - (dash)
        ' (single quote) 
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

bool isPunc(char c)
{
    string punctuation = ".;,?-'";
    for (char p : punctuation)
        if (c == p) return true;

    return false;
}

int main()
{
    cout << "Enter a command: ";
    string command;
    getline(cin, command);

    vector<string> words;
    stringstream stream {command};
    for (string s; stream >> s; )
        words.push_back(s);
    
    for (string s : words) 
    {
        string temp;
        for (char c : s) {
            if (isPunc(c))
                c = ' ';
            
            temp += c;
        }

        cout << temp << " ";
    }
}