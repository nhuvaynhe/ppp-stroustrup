/*
    Question 1.
    Chapter 11, page 408.

     Write a program that reads a text file and converts its input to all lower 
    case, producing a new file.
*/

#include <iostream>
#include <vector>
#include <ctype.h>
#include <fstream>
using namespace std;

void getLOWER(vector<string>& ss)
{
    for (int i=0; i<ss.size(); ++i)
    {
        string s;
        for (char c : ss[i]){
            c = tolower(c);
            s += c;
        }

        ss[i] = s;
    }
}

int main()
{
    ifstream getIN {"UPPERcase.txt"};
    if (!getIN) {
        cerr << "can't open the file";
        exit(1);
    }

    vector<string> store;

    string temp;
    while (getIN >> temp)
        store.push_back(temp);

    ofstream getOUT {"converted.txt"};

    getLOWER(store);
    for (string ss : store)
        getOUT << ss << " ";   
 
}