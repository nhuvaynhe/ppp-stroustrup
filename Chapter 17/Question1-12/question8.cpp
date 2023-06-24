/*
    Question 8.
    Chapter 17, page 624.
    Date: 04/05/2023
 
    Do exercise 7 again, but this time read into a std::string rather than to 
    memory you put on the free store (string knows how to use the free store 
    for you).
*/

#include <iostream>
using namespace std;

int main()
{
    char c_in;
    string str_in;

    while (cin >> c_in && c_in != '!')
        str_in += c_in;

    cout << str_in;
}