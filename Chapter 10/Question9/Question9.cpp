/*
    Question 9.
    Chapter 10, page 378.
    15/04/2023

    Write a program that takes two files containing sorted whitespace-separated 
    words and merges them, preserving order.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

//---------------------------------------------------------------
void getFile(string file1, string file2)
{
    ifstream f1 {file1};
    ifstream f2 {file2};
    ofstream f3 {"file3.txt"};

    vector<string> v_words;
    string temp;

    while (f1 >> temp)
        v_words.push_back(temp);
    while (f2 >> temp)
        v_words.push_back(temp);
  
    sort(v_words.begin(), v_words.end());

    for (string s : v_words)
        f3 << s << " ";
}
//---------------------------------------------------------------
int main()
{
    string file1, file2;

    cout << "Enter the name of the first file:" << endl;
    cin >> file1;
    cout << "Enter the name of the second file:" << endl;
    cin >> file2;

    getFile(file1, file2);
}