/*
    Question 14.
    Chapter 9, page 341.

    Money.h

    Represent a monetary amount as a number of cents in a long int,
    but input and output as dollars and cents
*/

#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
//----------------------------------------------------------------------

class Money
{
public:
    Money();

    void menu();
private:
    void getInput();

    void print();
    void getCent();

    double dollar;
    long int cent;
};

#endif