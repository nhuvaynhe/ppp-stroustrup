/*
    Question 10.
    Chapter 17, page 624.
    Date: 04/05/2023
 
    Look at your solution of exercise 7. Is there any way that input could 
    get the array to overflow; that is, is there any way you could enter more 
    characters than you allocated space for (a serious error)? Does anything 
    reasonable happen if you try to enter more characters than you allocated?
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
    int maxMemory = 10;
    char* charInput = new char[maxMemory];

    for(int i = 0; i < maxMemory; ++i)
    {
        char c_input;

        cout << "Input character [" << i << "]: ";
        cin >> c_input;
        charInput[i] = c_input;

        if (c_input == '!') {
            print(charInput);
            return 0;
        }
    }

    cout << "\n-------------------------------------------------------------------------- ";
    cout << "\n\tOverflow detected!";
}

