/*  
    Drill 5, 9.7.4
    Chapter 9, page 338.
    07/04/2023
    Getting the sequence of versions of 'Date' to work.
*/

#include "std_lib_facilities.h"

enum class Month {
    jan=1, feb, mar, apr, may, jun, 
    jul, aug, sep, oct, nov, dec
};

//------------------------------------------------------------------
// simple Date (control access)

class Date {
public:
    Date(int y, Month m, int d);  // check for valid date and initialize

    Month month() const { return m; }
	int day() const { return d; }
	int year() const { return y; }

    void add_day(int n);        // icrease the Date by n days
    void add_month(int m);
    void add_year(int y);
private:
    int y, d;                // year, month, day
    Month m;
};
//------------------------------------------------------------------

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

//------------------------------------------------------------------

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
//------------------------------------------------------------------
void Date::add_month(int n)
{
    // if m += m > 12, then make it 1, else return m
    int nextM = int(m) + n;
    if (nextM > 12) {
        m = Month::jan;
        add_year(1);
    }
    else m = Month(nextM);
}
//------------------------------------------------------------------
void Date::add_year(int n)
{   
    y += n;
    if (y > 3000){
            cout << "No way!\n";
            y -= n; 
        }
}
//------------------------------------------------------------------
ostream& operator<<(ostream& os, const Date& dd)
{
    return os << '(' << dd.year()
             << ',' << int(dd.month())
             << ',' << dd.day() << ")\n";
}


int main()
{   
    const Date today = Date{2023, Month::mar,6};
    Date tomorrow( today );
    Date nextmonth( today );
    Date nextyear( today );

    tomorrow.add_day(1);
    nextmonth.add_month(1);
    nextyear.add_year(1);

    cout << "\nToday is: "<<today;
    cout << "\nTomorrow is: "<<tomorrow;
    cout << "\nNext month is: "<<nextmonth;
    cout << "\nNext year is: "<<nextyear;
}