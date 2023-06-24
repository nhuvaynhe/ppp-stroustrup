//Drill of chapter 3, page 126

#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> word = {};
    
    string sInput = " ";

    cout<<"Please enter a word: ";
    while (cin>>sInput)
    {
        word.push_back(sInput);
    }

    sort(word.begin(), word.end());
    
    string sMode = " ";
    int nCount = 1;
    int nMax = 1;

    for (int i = 0; i <= word.size(); ++i)
    {
        if (word[i] == word [i-1])
        {
            ++nCount; 
        } else {
            nCount = 1;
        }

        if (nMax < nCount)
        {
            sMode = word[i];
            nMax = nCount;
        }
    }

    cout<<"\nSmallest: "<<word[0];
    cout<<"\nLargest: "<<word[word.size()-1];
    cout<<"\nMode = "<<sMode<<" with "<<nMax<<" times";
}