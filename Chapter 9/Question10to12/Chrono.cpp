/*
    Question 10.
    Chapter 9, page 334

    file Chrono.cpp
    Defininions of Chrono.h
*/

#include "Chrono.h"

namespace Chrono {
// member function definitions:

Date::Date(int yy, Month mm, int dd)
    : y{yy}, m{mm}, d{dd}
{
    if (!is_date(yy,mm,dd)) throw Invalid{};
}

const Date& default_date()
{
    static Date dd {2001, Month::jan, 1};       // start of 21st century
    return dd;
}

Date::Date()
    :y{default_date().year()},
    m{default_date().month()},
    d{default_date().day()}
{
}

void Date::add_day(int n)
{
    //...
}

void Date::add_month(int n)
{
    //...
}

void Date::add_year(int n)
{
    if (m==Month::feb && d==29 && !leapyear(y+n)) {    // beware of leap years!
        m = Month::mar;                    // use March 1 instead of February 29
        d = 1;
    }
    y += n;
}
//---------------------------------------------------------------------
//helper function:
bool is_date(int y, Month m, int d)
{
    // assume that y is valid

    if (d<=0) return false;
    if (m<Month::jan || Month::dec<m) return false;

    int days_in_month = 31;

    switch (m) {
    case Month::feb:
        days_in_month = (leapyear(y))?29:28;
        break;
    case Month::apr: case Month::jun: case Month::sep: case Month::nov:
        days_in_month = 30;
        break;
    }

    if (days_in_month<d) return false;

    return true;
}

bool leapyear(int y)
{
    if (y % 4 == 0) 
    {
        if (y % 100 == 0) {
            if (y % 400 == 0) return true;
            else return false;
        }
        else return true;
    } 
    else return false;
}
//-----------------------------------------------------------------------------------
int daysSince1stJan(const Date& d)
{
    int day = d.day();
    int month = int(d.month());
    int year = d.year();

    int sum = 0;

    for (int i=1; i <= month; ++i)
    {   
        if (i == month) { sum += day; }
        else if (month == 4 || month == 6 || month ==9 || month == 11) { sum += 30;}
        else if (month == 2)
            {
                if (leapyear(year)) sum += 29;
                else sum += 28;
            } 
        else sum += 31; 
    }

    return sum;
}

int weekofYear(const Date& d)
{   
    // daysSince1stJan is an int so we must change it to double so that we can round up.
    double weeks = static_cast<double>(daysSince1stJan(d)-1) / 7;
    return ceil(weeks + 1);
    // i add 1 because we count from 1 to today.
    // based on the timetable on mybk to check the answer.
    // minus one because i dont think 1st Jan should be counted as a week!.
}

int daysSince1stJan1970(const Date& d) // number of days since 1/1/1970
{
    // Beware of leapyear
    int year = d.year();            
    int month = int(d.month());
    int day = d.day();

    long int numofDays = daysSince1stJan(d);        // number of days from 1/1 of this year

    if (year < 1970) {
        cout << "Wrong year!";
        return 0;
    }

    for (int i = 1970; i < year; ++i)
    {
        if (leapyear(i)) {
            numofDays += 366;
        } else {
            numofDays += 365;
        }
    }

    return (numofDays -1) ;       // i dont know whether should we add the day 1/1/1970 itself or not
}

int daysBetween(const Date& d1, const Date& d2)
{
    int year1 = d1.year();            
    int month1 = int(d1.month());
    int day1 = d1.day();

    int year2 = d2.year();            
    int month2 = int(d2.month());
    int day2 = d2.day();

    if (year1 > year2) {
        cout << "The second argument must be larger or equal";
        return 0;
    } else if (year1 == year2 && month1 > month2) {
        cout << "The second argument must be larger or equal";
        return 0;
    } else if (year1 == year2 && month1 == month2 && day1 > day2) {
        cout << "The second argument must be larger or equal";
        return 0;
    } 

    long int days = daysSince1stJan(d2);
    if (leapyear(year1)) days += (366 - daysSince1stJan(d1));
    else days += (365 - daysSince1stJan(d1));

    if (year2 - year1 != 0) { 
        for (int i = year1 + 1; i < year2; ++i)
        {
            if (leapyear(i)) {
                days += 366;
            } else {
                days += 365;
            }
        }
    }

    return days;
}
//-----------------------------------------------------------------------------------
bool operator==(const Date& a, const Date& b)
{
    return a.year()==b.year()
        && a.month()==b.month()
        && a.day()==b.day();
}

bool operator!=(const Date& a, const Date& b)
{
    return !(a==b);
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os<<'('<<d.year()
             <<','<<int(d.month())
             <<','<<d.day()<<')';
}

istream& operator>>(istream& is, Date& dd)
{
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if (!is) return is;
    if (ch1 !='(' || ch2!=',' || ch3!=',' || ch4!=')') {    // format error
        is.clear(ios_base::failbit);                        // set the fail bit
    return is;
    }

    dd = Date(y, Month(m), d);  // update dd

    return is;
}
//-----------------------------------------------------------------------------------
ostream& operator<<(ostream& os, const Day& d)
{
	switch (d)
	{
	case Day::monday:
		return os << "Monday";
	case Day::tuesday:
		return os << "Tuesday";
	case Day::wednesday:
		return os << "Wednesday";
	case Day::thursday:
		return os << "Thursday";
	case Day::friday:
		return os << "Friday";
	case Day::saturday:
		return os << "Saturday";
	case Day::sunday:
		return os << "Sunday";
	default:
		return os << "Something weird happened in operator<<(Day).";
	}
}
//-----------------------------------------------------------------------------------
Day day_of_week(const Date& d)
{
    int days = (daysSince1stJan(d));

    return Day((days % 7));
}

Day next_workday(const Date& d)
{
    Day today = day_of_week(d);
    Day next_word_day = Day(int(today) + 1);

    switch (next_word_day){
        case Day::sunday: case Day::saturday: {
            next_word_day = Day::monday;
        }
        default:
            next_word_day;   
    }
    return next_word_day;
}

Date next_Sunday(const Date& d)
{
    //.... 
}

Date next_weekday(const Date& d)
{
    //....
}



}       // Chrono