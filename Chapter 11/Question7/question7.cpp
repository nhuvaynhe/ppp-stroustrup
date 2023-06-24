/*
    Question 6.
    Chapter 11, page 409.
    Date: 19/04/2023

    Modify the program from the previous exercise so that it replaces don't 
    with do not, can't with cannot.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

bool isQuote(char c)        // ' : single
{
    string quote = "'";
    for (char p : quote)
        if (c == p) return true;

    return false;
}

void convert(string& temp)
{
    if (temp == "don") temp = temp.erase(2)+ " no";
    if (temp == "can") temp += "no";
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
            c = tolower(c);
            if (isQuote(c) && temp == "don" || temp == "can") 
            {
                c = '\0';
                convert(temp);
            }
            
            temp += c;
        }

        cout << temp << " ";
    }
}