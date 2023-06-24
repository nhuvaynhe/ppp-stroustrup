/*
    Question 11.
    Chapter 11, page 409.
    Date: 20/04/2023

    Write a function vector<string> split(const string& s, const string& w) 
    that returns a vector of whitespace-separated substrings from the argu-
    ment s, where whitespace is defined as “ordinary whitespace” plus the 
    characters in w.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <ctype.h>
#include <algorithm>
using namespace std;

bool whiteSpace(const string& w, char c)
{
    for (char key : w) {
        if (c == key) return true;
    }

    return false;
}

vector<string> split(const string& s, const string& w)
{
    string temp; 
    vector<string> splitString;

    for (char c : s)
    {
        if (isspace(c) || whiteSpace(w, c)) {
            c = '\0';

            if (!temp.empty()) {
                splitString.push_back(temp);
            }
            
            temp.clear();
        } else temp += c;
    }

    splitString.push_back(temp);
    return splitString;
}

int main()
{
    const string s = "Con mua, ngang? qua";
    const string w = ",?";

    vector<string> stringsplit = split(s, w);

    for (string ss : stringsplit)
        cout << ss << endl;
}