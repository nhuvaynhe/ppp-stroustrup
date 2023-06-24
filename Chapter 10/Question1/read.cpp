/*
    Question 1.
    Chapter 10, page 377.
    The sum of all the numbers in a file of whitespace-separated integers.
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    string filename = "mydata.txt";

    fstream fs(filename);
    int sum = 0; 

    for (int i; fs >> i; )
    {
        sum += i;
    }

    cout << "The sum of all the numbers in file is: " << sum <<endl;
}