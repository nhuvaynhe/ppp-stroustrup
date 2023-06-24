/*
    Question 11.
    Chapter 11, page 409.
    Date: 20/04/2023

    Write a program to read a file of whitespace-separated numbers and out-
    put them in order (lowest value first), one value per line.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <ctype.h>
#include <algorithm>
using namespace std;
//--------------------------------------------------------------------------
bool isDuplicate(double i, vector<double> v)
{   
    int ite = 0;

    for (double d : v)
        if (i == d) ite += 1;
    
    if (ite > 1) return true;
    
    return false;
}
//--------------------------------------------------------------------------
int countDuplicates(double num, int location, vector<double>& v)
{
    int duplicates = 1;

    for (int i=location; i<v.size(); ++i) {
        if (num == v[i]) 
        {
            ++duplicates;
            v.erase(v.begin()+i);
        }
    }
        
    
    return duplicates;
}
//--------------------------------------------------------------------------
void getValue(vector<double> numbers)
{
    for (int i=0; i<numbers.size(); ++i)
    {   
        double d = numbers[i];

        if (isDuplicate(d,numbers)) {
            int ite = countDuplicates(d, i, numbers);
            cout << d << '\t' << ite << endl;

        } else cout << d << endl;
    }
}
//-------------------------------------------------------------------------- 
int main()
{
    fstream readIn {"number.txt"};

    double num;
    vector<double> numbers;
    while (readIn >> num)
        numbers.push_back(num);

    getValue(numbers);
}