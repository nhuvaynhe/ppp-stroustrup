/*
    Question 7.
    Chapter 17, page 624.
    Date: 04/05/2023
 
    Write a program that reads characters from cin into an array that you 
    allocate on the free store. Read individual characters until an exclamation 
    mark (!) is entered. Do not use a std::string. Do not worry about memory exhaustion.
*/

#include <iostream>
using namespace std;

void print(char* c)
{
    while (*c != '\0') 
    {
        cout << *c << " ";
        ++c;
    }
}

int main()
{   
    int maxMemory = 200000;
    char* charInput = new char[maxMemory];

    for(int i = 0; i < maxMemory; ++i)
    {
        char c_input;

        cout << "Input character [" << i << "]: ";
        cin >> c_input;
        charInput[i] = c_input;

        if (c_input == '!') 
            print(charInput);
    }
}

