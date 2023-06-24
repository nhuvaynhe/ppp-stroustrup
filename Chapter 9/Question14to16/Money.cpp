/*
    Question 14.
    Chapter 9, page 341.

    Money.cpp

    Represent a monetary amount as a number of cents in a long int,
    but input and output as dollars and cents
*/

#include "Money.h"

//----------------------------------------------------------------------
Money::Money() { }


void Money::menu()
{
    cout << "-----Money Class----" << endl;

    getInput();
    getCent();
    print();
}

void Money::getInput()
{   
    double input;
    cout << "Enter the number of dollars: " <<endl;
    cin >> input;

    dollar = input;
}

void Money::getCent()
{
    double centDouble = dollar * 100.0f;        // 100.0f return double, more precise

    cent = round(centDouble);
}

void Money::print()
{   
    // without fixed flag: 1.2
    // with fixed flag: 1.20
    cout << "Dollar: $" << fixed << setprecision(2) << dollar << endl;
    cout << "Cent: " << fixed << setprecision(0) << cent << endl;

    //return to main menu
    system("pause");
    system("CLS");
    cent = dollar = 0;
    menu();

}