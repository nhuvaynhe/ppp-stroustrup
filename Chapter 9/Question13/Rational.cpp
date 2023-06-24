/*
    Question 13.
    Chapter 9, page 334

    Rational.cpp
*/

#include "Rational.h"
//----------------------------------------------------------------
Rational::Rational(int nume, int deno) 
    : numerator{nume}, denominator {deno}
{
    if (deno == 0) throw Invalid{};
}

//----------------------------------------------------------------
// Helper function
double convert(const Rational& r){
    double r_nume = static_cast<double>(r.get_nume());
    double r_deno = static_cast<double>(r.get_deno());

    return r_nume/r_deno;
}
//----------------------------------------------------------------
int common_division(int num1, int num2)    // return Greatest common division of 2 nums
{
    int min;
    if (num1 > num2) min = num2;
    else min = num1;

    int smallest_common;
    for (int i=1; i<=min; ++i)
    {
        if (num1 % i == 0 && num2 % i == 0) {
            smallest_common = i;
        }
    }

    return smallest_common;
}
int common_multiply(int num1, int num2)    // return Greatest common division of 2 nums
{
    int smallest_common = common_division(num1, num2);
    int greatest_common = (num1*num2)/smallest_common;

    return greatest_common;
}
//----------------------------------------------------------------
Rational roundup(const Rational& r)
{
    int nume = r.get_nume(); 
    int deno = r.get_deno();

    int smallest_common = common_division(nume, deno);

    return Rational(nume/smallest_common, deno/smallest_common);
}
//----------------------------------------------------------------
Rational operator*(const Rational& r1, const Rational& r2)
{
    int numerator = r1.get_nume() * r2.get_nume();
    int denominator = r1.get_deno() * r2.get_deno();

    return roundup(Rational(numerator, denominator));
}
//----------------------------------------------------------------
Rational operator+(const Rational& r1, const Rational& r2)
{   
    int nume;
    int deno;

    int scale;
    int deno_1 = r1.get_deno();
    int deno_2 = r2.get_deno();

    if (deno_1 % deno_2 == 0) {
        scale = deno_1/deno_2; 

        nume = r1.get_nume() + r2.get_nume()*scale;
        deno = deno_1;

    } else if (deno_2 % deno_1 == 0) {
        scale = deno_2/deno_1; 

        nume = r1.get_nume()*scale + r2.get_nume();
        deno = deno_2;
    } else {
        scale = common_multiply(deno_1, deno_2);

        int scale_1 = scale/deno_1;
        int scale_2 = scale/deno_2;

        nume = r1.get_nume()*scale_1 + r2.get_nume()*scale_2;
        deno = scale;
    }

    return roundup(Rational(nume, deno));
}
//----------------------------------------------------------------
Rational operator-(const Rational& r1, const Rational& r2)
{
    int nume = r1.get_nume()*r2.get_deno() - r2.get_nume()*r1.get_deno();
    int deno = r1.get_deno()*r2.get_deno();

    return roundup(Rational(nume, deno));
}
//----------------------------------------------------------------
Rational operator/(const Rational& r1, const Rational& r2)
{   
    // Division of Rational number equal multiply with upside Down num
    Rational r2_upsideDown = Rational(r2.get_deno(), r2.get_nume());
    return roundup(r1*r2_upsideDown);
}
//----------------------------------------------------------------
ostream& operator<<(ostream& os, const Rational& r)
{
    return os << r.get_nume() << '/' << r.get_deno();
}

