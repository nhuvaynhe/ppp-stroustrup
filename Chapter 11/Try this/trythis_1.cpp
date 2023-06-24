/*
    Try this #1.
    Chapter 11, page 382.

    Output your birth year in decimal, hexadecimal, and octal form. Label each 
    value. Line up your output in columns using the tab character. Now output 
    your age.
*/

#include <iostream>
using namespace std;

int main()
{
    int birth_year = 2002;
    cout << "\ndecimal: " << '\t' << birth_year << '\n'
         << "hexadecimal: " << hex << '\t' << birth_year << '\n'
         << "octal: " << oct << "\t\t" << birth_year << '\n';

    int my_age = 21;
    cout << "\ndecimal: " << '\t' << my_age << '\n'
         << "hexadecimal: " << hex << '\t' << my_age << '\n'
         << "octal: " << oct << "\t\t" << my_age << '\n';

    cout << showbase << dec;        // ask the ostream to show the base of each integer printed

    cout << "\ndecimal: " << '\t' << birth_year << '\n'
         << "hexadecimal: " << hex << '\t' << birth_year << '\n'
         << "octal: " << oct << "\t\t" << birth_year << '\n';

    cout << "\ndecimal: " << '\t' << my_age << '\n'
         << "hexadecimal: " << hex << '\t' << my_age << '\n'
         << "octal: " << oct << "\t\t" << my_age << '\n';

}