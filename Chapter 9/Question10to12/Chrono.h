/*
    Question 10.
    Chapter 9, page 334

    file Chrono.h
*/

#ifndef CHRONO_H
#define CHRONO_H

#include "std_lib_facilities.h"

namespace Chrono {
    
enum class Month {
    jan=1, feb, mar, apr, may, jun, jul,
    aug, sep, oct, nov, dec
};

enum class Day {
    saturday=0, sunday, monday, tuesday, wednesday, thursday, friday, 
};
//-----------------------------------------------------------------------------------
class Date {
public:
    class Invalid { };              // to throw as exception

    Date(int y, Month m, int d);    // check for valid date 
    Date();                         // default constructor


    // nonmodifying operations
    int day() const { return d; }
    Month month() const { return m; }
    int year() const { return y; }

    // modifying operations:
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);
private:
    int y;
    Month m;
    int d;
};

bool is_date(int y, Month m, int d);    // true for valid date
bool leapyear(int y);                   // true if y is a leap year
int daysSince1stJan(const Date& d);     // number of days since 1/1/this year
int weekofYear(const Date& d);

int daysSince1stJan1970(const Date& d); // number of days since 1/1/1970
int daysBetween(const Date& d1, const Date& d2);

Day day_of_week(const Date& d);
Day next_workday(const Date& d);


bool operator==(const Date& a, const Date& b);
bool operator!=(const Date&a, const Date& b);

ostream& operator<<(ostream& os, const Day& d);

ostream& operator<<(ostream& os, const Date& d);

istream& operator>>(istream& is, Date& dd);

}           // Chrono

#endif