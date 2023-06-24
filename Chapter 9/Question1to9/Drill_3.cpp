/*  
    Drill 3, 9.4.3
    Chapter 9, page 338.
    07/04/2023
    Getting the sequence of versions of 'Date' to work.
*/

#include "std_lib_facilities.h"

enum class Month {
    jan=1, feb, mar, apr, may, jun, 
    jul, aug, sep, oct, nov, dec
};

// simple Date (control access)
class Date {
    int y, d;                // year, month, day
    Month m;
public:
    Date(int y, Month m, int d);  // check for valid date and initialize

    void add_day(int n);        // icrease the Date by n days

    Month month() { return m; }
    int day() { return d; }
    int year() { return y; }
};

Date::Date(int yy, Month mm, int dd)
{
    if (yy < 1900 || 2200 < yy) 
        cout << "Error, invalid year.\n" << endl;
    else if (int(mm) < 1 || 12 < int(mm)) 
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
    // if d += n > 31, then make it 1, else return d
    int sum = d + n;
    if (sum > 31)
    {
        d = 1;
        int nextM = int(m) + 1;
        if (nextM > 12) {
            m = Month::jan;
            if (++y > 3000)
                cout << "No way!\n";
        }
        else m = Month(nextM);
    } else d = sum;
}

ostream& operator<<(ostream& os, Date& dd)
{
    return os << '(' << dd.year()
             << ',' << int(dd.month())
             << ',' << dd.day() << ")\n";
}


int main()
{
    Date today = Date{2023, Month::dec, 31};

    Date tomorrow( today );
    tomorrow.add_day(1);

    cout << "\nToday is: "<<today;
    cout << "\nTomorrow is: "<<tomorrow;
}

