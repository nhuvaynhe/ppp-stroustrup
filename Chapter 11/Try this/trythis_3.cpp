/*
    Try this #3.
    Chapter 11, page 382.

    Write  some  code  to  print  the  number  1234567.89  three  times,  first  using 
    defaultfloat, then fixed, then scientific. Which output form presents the user 
    with the most accurate representation? Explain why.
*/

#include <iostream>
#include <iomanip>  
using namespace std;

int main()
{
    float num = 1234567.89;

    cout << "default float: " << "\t\t" << defaultfloat << num << '\n'
         << "fixed: " << "\t\t\t" << fixed << num << '\n'
         << "scientific: " << "\t\t" << scientific << num;

    cout << "\n\ndefault float: " << "\t\t" 
                              << setprecision(8) << defaultfloat << num << '\n'
         << "fixed: " << "\t\t\t" << fixed << num << '\n'
         << "scientific: " << "\t\t" << scientific << num;
}