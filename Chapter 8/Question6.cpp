/*
	Question 6.
    Chapter 8, page 301
    Date: 03/04/2023
    Reverse the order of elements in vector, string version. 
*/

#include "std_lib_facilities.h"

vector<string> v_reversed;

void reverseVector1(vector<string> v)
{
    for (int i = v.size() - 1; i >= 0; --i){
        v_reversed.push_back(v[i]);
    }
}

void reverseVector2(vector<string>& v)
{
    for (int i = 0; i <= (v.size()/2 -1); ++i){
        string swap = v[i];
        v[i] = v[v.size() -i -1];
        v[v.size() -i -1] = swap;
    }
}

void printVector(vector<string>& v)
{   
    if (v.size() == 0) cout << "Empty vector";

    cout << "\nThe order is: ";
    for (int i = 0; i < v.size(); ++i){
        if ( i == v.size() - 1) cout << v[i] << '\n';
        else cout << v[i] <<", ";
    }
}

int main()
{
    vector<string> v;
    string input;
    while (cin >> input){
        if (!cin) error("Wrong intput");
        if (input == "=") break;
        v.push_back(input);
    }

    reverseVector1(v);
    reverseVector2(v);

    printVector(v_reversed);
    printVector(v);
}