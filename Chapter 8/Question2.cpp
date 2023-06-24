/*
	Question 2.
    Chapter 8, page 300
    Date: 03/04/2023
    Write the function print out vector.
*/

#include "std_lib_facilities.h"

void printVector(vector<int>& v, string name)
{
    cout << name << '\n';
    for (int x : v){
        cout << x <<'\n';
    }
}

int main()
{
    vector<int> q1 = {};
    int input;
    while (cin >> input){
        if (!cin) error("wrong intput");
        q1.push_back(input);
    }

    string name = "Question 1";
    printVector(q1, name);
}