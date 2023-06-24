/*
    Question 10.
    Chapter 11, page 409.
    Date: 20/04/2023

    Write a function vector<string> split(const string& s) that returns a  vector 
    of whitespace-separated substrings from the argument s.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <ctype.h>
#include <algorithm>
using namespace std;

vector<string> split(const string& s)
{
    string temp; 
    vector<string> splitString;

    for (char c : s)
    {
        if (isspace(c)) {
            splitString.push_back(temp);
            c = '\0';
            temp = "";
        } else temp += c;
    }

    splitString.push_back(temp);
    return splitString;
}

int main()
{
    const string s = "Con mua ngang qua";

    vector<string> stringsplit = split(s);

    for (string ss : stringsplit)
        cout << ss << endl;
}