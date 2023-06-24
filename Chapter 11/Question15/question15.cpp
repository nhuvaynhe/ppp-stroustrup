/*
    Question 11.
    Chapter 11, page 409.
    Date: 20/04/2023

    Write a program that reads a file of whitespace-separated numbers and 
    outputs a file of numbers using scientific format and precision 8 in four 
    fields of 20 characters per line.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <ctype.h>
#include <algorithm>
using namespace std;

int main()
{
    fstream readIn {"number.txt"};

    double num;
    vector<double> numbers;
    while (readIn >> num)
        numbers.push_back(num);

    int fields = 0;

    for (double i : numbers) {
        if (fields == 4) {
            cout << endl;
            fields = 0;
        }

        cout << setprecision(8) << scientific 
             << setw(20) << i;
        ++fields;
    }
        
}