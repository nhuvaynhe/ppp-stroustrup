/*
    Question 11.
    Chapter 11, page 409.
    Date: 20/04/2023

    Reverse the order of words (defined as whitespace-separated strings) in a file. 
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <ctype.h>
#include <algorithm>
using namespace std;

void reversed(vector<string>& words)
{
    for (int i = words.size() -1; i >= 0; --i)
    {
        cout << words[i] << " ";
    }

    words.clear();
    cout << endl;
}

int main()
{
    fstream readIn {"text.txt"};

    string temp;
    vector<string> store;

    while (getline(readIn, temp))
    {
        stringstream ss {temp};

        for (string s; ss >> s; )
            store.push_back(s);

        reversed(store);
    }
    
}