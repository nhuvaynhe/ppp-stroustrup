/*
[9:22 AM] Nguyen Quang Vinh (MS/EAS42-CC)
    1. A leap year is exactly divisible by 4 except for century years (years ending with 00). 
   The century year is a leap year only if it is perfectly divisible by 400.
   For example:
        1999 is not a leap year
        2000 is a leap year
        2004 is a leap year
   Write a number to check Leap year.
    
    2. Write a function to find Sum of Max number and Min number of an array
    ex: 
        input:     a[10] = [5, 3, 8, 4, 6, 5, 9, 0, 2, 7]    
        Sum = 9

*/

#include <iostream>
using namespace std;

bool isLeapyear(int year)
{
    if(year % 100) return true;
    if(year % 4 == 0) return true;

    return false;
}

int main()
{
    int year = 2000;
    cout << isLeapyear(year);
}