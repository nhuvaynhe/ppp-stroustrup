/*
    Question #5.
    Chapter 18, page 665.
    Date: 08/05/2023.

    Write  a  function,  string  cat_dot(const  string&  s1,  const  string&  s2), 
    that concatenates two strings with a dot in between. For example, cat_
    dot("Niels", "Bohr") will return a string containing Niels.Bohr.
*/

#include <iostream>
using namespace std;

string cat_dot(const string& s1, const string& s2, const string& arg)
{
    string temp = s1 + arg + s2;

    return temp;
}   

int main()
{
    string prev = "Dai";
    string succ = "Ngoc";
    string seper = "-->";

    cout << cat_dot(prev, succ, seper);
}