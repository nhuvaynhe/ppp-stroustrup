/*  
    Drill 4, 9.7.1
    Chapter 9, page 338.
    07/04/2023
    Getting the sequence of versions of 'Date' to work.
*/

#include "std_lib_facilities.h"

enum class Month {
    jan=1, feb, mar, apr, may, jun, 
    jul, aug, sep, oct, nov, dec
};
//------------------------------------------------------------------------
class Year {
    static const int min = 1800;
    static const int max = 2200;
public:
    class Invalid { };
    Year(int x) : y{x} { if (x<min || max<=x) throw Invalid{}; }
    int year() { return y; }
private:
    int y;
};
//------------------------------------------------------------------------
// simple Date (use Month type)
class Date {
public:
    Date(Year y, Month m, int d);

    int day() const { return d; }
    Month month() const { return m; }
    Year year() const { return y; }

    void add_day(int n);        // icrease the Date by n days

private:
    Year y;
    Month m;
    int d;  
};

Date::Date(Year(yy), Month mm, int dd)
{
    if (dd < 1 || 31 < dd) 
        cout << "Error, invalid day.\n" << endl;
    else if (int(mm) < 1 || 12 < int(mm)) 
        cout << "Error, invalid month.\n" << endl;
    else
    {
        y = yy; d = dd; m = mm;
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

ostream& operator<<(ostream& os, const Date& dd)
{
    return os << '(' << dd.year()
             << ',' << int(dd.month())
             << ',' << dd.day() << ")\n";
}


int main()
{
    Date today = Date{Year{2023}, Month::dec, 7};

    Date tomorrow( today );
    tomorrow.add_day(1);

    cout << "\nToday is: "<<today;
    cout << "\nTomorrow is: "<<tomorrow;
}
