/*
    Question 3.
    Chapter 11, page 409.
    Date: 18/04/2023

    Write a program that removes all vowels from a file (“disemvowels”). For 
    example, Once upon a time! becomes nc pn tm!. Surprisingly often, the 
    result is still readable; try it on your friends.
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool isVowel(char c)
{
    string vowel = "aeiou";

    for (char v : vowel)
        if (v == c) return true;

    return false;
}

int main()
{
    fstream getIN {"text.txt"};
    if (!getIN) {
        cerr << "can't open the file";
        exit(1);
    }

    string data;
    vector<string> store;
    ofstream getOUT {"output.txt"};

    while (getline(getIN,data)){

        string temp;
        // the last word in the input file may not be followed by a whitespace character, 
        // which is used as a trigger to output the word.
        for (char c : data) { 
            if (isspace(c)) {
                getOUT << temp << " ";
                temp = "";
            } else if (!isVowel(c)) 
                temp += c;
         
        }

        if (!temp.empty()) {
            getOUT << temp;
        }

        getOUT << endl;
    }
}
