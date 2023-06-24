/*
    Drill.
    Chapter 11, page 407.
    Date: 18/04/2023

    Test_output.cpp
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int birth_year = 2002;
    cout << showbase << dec;
    cout << "My birth year in " << '\n'
         << "\tdecimal: " << '\t' << birth_year << '\n'
         << hex << "\thexadecimal: " << '\t' << birth_year << '\n'
         << oct << "\toctal: " << "\t\t" << birth_year;

    int my_age = 21;

    cout << "\n\nMy age in " << '\n'
         << "\tdecimal: " << dec <<  '\t' << my_age << '\n'
         << "\thexadecimal: " << hex << '\t' << my_age << '\n'
         << "\toctal: " << oct << "\t\t" << my_age << '\n';
}