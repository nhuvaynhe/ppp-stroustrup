// Convert Celsius to Kelvin
// Question 2, page 169
// 16/03/2023

#include "std_lib_facilities.h"
using namespace std;

double c_to_f(double c)
{
    
    if (c < -273.15) 
    {
        cerr << "This temperature is below absolute zero!!! \n";
    }
    else {
        double f = (9*c/5) + 32;
        cout << f << "\n";
    }
}

double f_to_c(double f)
{
    double c = (f - 32)*5/9;
    if (c < -273.15) 
    {
        cerr << "This temperature is below absolute zero!!! \n";
    }
    else {
        cout << c << "\n";
    }
}

int main()
{
   double f = 0;
   cin >> f;
   f_to_c(f);
}