/*  
    Drill 2, 9.4.2
    Chapter 9, page 338.
    07/04/2023
    Getting the sequence of versions of 'Date' to work.
*/

#include "std_lib_facilities.h"

// Simple Date
// guarantee initalization with constructor
// provide some notational convenience
struct Date {
    int y, m ,d;
    Date(int y, int m, int d);
    void add_day(int n);
};

Date::Date(int yy, int mm, int dd)
{
    if (yy < 1900 || 2200 < yy) 
        cout << "Error, invalid year.\n" << endl;
    else if (mm < 1 || 12 < mm) 
        cout << "Error, invalid month.\n" << endl;
    else if (dd < 1 || 31 < dd) 
        cout << "Error, invalid day.\n" << endl;
    else
    {
        y = yy; m = mm; d = dd;
    }
}

void Date::add_day(int n)
{
    d += n;
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y
             << ',' << d.m
             << ',' << d.d << ")\n";
}


int main()
{
    Date today = Date{2023, 4, 7};

    Date tomorrow( today );
    tomorrow.add_day(1);

    cout << "\nToday is: "<<today;
    cout << "\nTomorrow is: "<<tomorrow;
}