/*
    Rational.h
*/

#ifndef RATIONAL_H
#define RATIONAL_H

#include "std_lib_facilities.h"

//----------------------------------------------------------------
class Rational
{
public:
    class Invalid { };              // to throw as exception

    Rational(int nume, int deno);
    int get_nume() const { return numerator; }
    int get_deno() const { return denominator; }

private:
    int numerator;
    int denominator;
};

//Helper function
double convert(const Rational& r);
int common_division(int num1, int num2);    // return Greatest common division of 2 nums
int common_multiply(int num1, int num2);    // return Smallest common multiplication of 2 nums

Rational roundup(const Rational& r);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator+(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);

ostream& operator<<(ostream& os, const Rational& r);

#endif