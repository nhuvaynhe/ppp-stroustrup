/*
    Question 13.
    Chapter 9, page 334

    main.cpp
*/

#include "Rational.h"
 
int main()
{
    Rational phanso1 = Rational(100, 4);
    Rational phanso2 = Rational(2, 6);

    cout << phanso1*phanso2 << endl;
    cout << phanso1+phanso2 << endl;
    cout << phanso1/phanso2 << endl;
    cout << phanso1-phanso2 << endl;
    cout << convert(phanso1) << endl;
    cout << convert(phanso2) << endl;
}