/*  
    Drill 1, 9.4.1
    Chapter 9, page 338.
    07/04/2023
    Getting the sequence of versions of 'Date' to work.
*/

#include "std_lib_facilities.h"

// Simple Date
struct Date {
    int y;  // year
    int m;  // month in year
    int d;  // day of month
};

void init_day(Date& dd, int y, int m, int d)
{
    if (y < 1900 || 2200 < y) 
        cout << "Error, invalid year.\n" << endl;
    else if (m < 1 || 12 < m) 
        cout << "Error, invalid month.\n" << endl;
    else if (d < 1 || 31 < d) 
        cout << "Error, invalid day.\n" << endl;
    else
    {
        dd.y = y;
        dd.m = m;
        dd.d = d;
    }
    
}

void add_day(Date& dd, int n)
{
    // increase dd.day by n 
    dd.d += n;
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y
             << ',' << d.m
             << ',' << d.d << ")\n";
}


int main()
{
    Date today;
    init_day(today, 2023, 4, 7);

    Date tomorrow( today );
    add_day(tomorrow, 1);

    cout << "\nToday is: "<<today;
    cout << "\nTomorrow is: "<<tomorrow;
}

