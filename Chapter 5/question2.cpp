// Convert Celsius to Kelvin
// Question 2, page 169
// 16/03/2023

#include <iostream>
using namespace std;

double c_to_k(double c)
{
    int k = c + 273.15;
    if (k < 0) 
    {
        cerr << "This temperature is below absolute zero!!! \n";
    }
    else {
        cout << k << "\n";
        return k;
    }
}

double k_to_c(double k)
{
    int c = k - 273.15;
    if (k < 0) 
    {
        cerr << "This temperature is below absolute zero!!! \n";
    }
    else {
        cout << c << "\n";
        return c;
    }
}

int main()
{
    double c1 = 0;
    cin >> c1;
    double k1 = c_to_k(c1);

    double k2 = 0;
    cin >> k2;
    double c2 = k_to_c(k2);
}