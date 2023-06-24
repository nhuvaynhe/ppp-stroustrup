/*
    Drill
    Chapter 10, page 376.
    12/04/2023.

    Pointclass.h
*/

#ifndef _POINTCLASS_H_
#define _POINTCLASS_H_
//--------------------------------------------------------------

#include <iostream>
#include <vector>
#include "std_lib_facilities.h"
#include <fstream>
using namespace std;

//--------------------------------------------------------------
class Point
{
public:
    Point() : x_cor(0), y_cor(0) {}

    Point(int x, int y);

    int x_cor;
    int y_cor;
};
//--------------------------------------------------------------
Point::Point(int x, int y)
    : x_cor(x), y_cor(y) { }


bool operator==(const Point& p1, const Point& p2)
{
    if (p1.x_cor - p2.x_cor == 0 && p1.y_cor - p2.y_cor == 0)  return true;
    else return false;
}


istream& operator>>(istream& is, Point& p)
{
    int x, y;
    char ch1, ch2, ch3;
    is >> ch1 >> x >> ch2 >> y >> ch3;
    if (!is) return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ')') {
        is.clear(ios_base::failbit);
        return is;
    }

    p = Point(x, y);
    return is;
} 

ostream& operator<<(ostream& os, Point& p)
{
    return os << p.x_cor << '\t' << p.y_cor << endl;
}

#endif