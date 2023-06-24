/*
    Question 2.
    Chapter 11, page 408.

    Write a program that given a file name and a word outputs each line that 
    contains that word together with the line number. Hint: getline().
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

bool findObject(string object, string data)
{
    stringstream line {data};
    vector<string> words;

    for (string s; line >> s; ){
        if (object == s) return true;
    }

    return false;
}
int main()
{
    fstream getIN {"text.txt"};
    if (!getIN){
        cerr << "can't open the file";
        exit(1);
    }

    string object;
    cout << "Enter the word that you want to find: ";
    cin >> object;

    string data;
    int line_num = 1;
    while (getline(getIN,data)){

        if (findObject(object, data)) {
            cout << line_num << '\t' << data << endl;
        } 

        ++line_num;
    }
}