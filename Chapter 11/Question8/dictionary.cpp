/*
    Question 8.
    Chapter 11, page 409.
    Date: 19/04/2023

    Make a dictionary with method of exercise 6.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <ctype.h>
#include <algorithm>
using namespace std;

//-------------------------------------------------------------------------- 
bool isPunc(char c)
{
    string punctuation = ".;,?-'!:";
    for (char p : punctuation)
        if (c == p) return true;

    return false;
}
//--------------------------------------------------------------------------
bool isDeclared(string key, vector<string> words)
{
    for (string s : words) {
        if (key == s) return true;
    }

    return false;
}
//--------------------------------------------------------------------------
void whiteSpace(string& word)
{
    string temp;
    for (char c : word) {
        c = tolower(c);
        if (!isPunc(c) || temp == "don" || temp == "can") 
            temp += c;

    }

    word = temp;
}
//--------------------------------------------------------------------------
void delete_duplicate(string s, vector<string>& words)
{
    whiteSpace(s);

    if (words.size() != 0) {

        if (!isDeclared(s, words))
            words.push_back(s);

    } else words.push_back(s);
}
//--------------------------------------------------------------------------
int main()
{   
    fstream getIN {"text.txt"};
    string command;
    vector<string> words;

    while (getline(getIN, command))
    {
        stringstream stream {command};

        for (string s; stream >> s; ) {
            delete_duplicate(s, words);
        }
    }
    
    sort(words.begin(), words.end());
    for (string s : words)
        cout << s << endl;
}