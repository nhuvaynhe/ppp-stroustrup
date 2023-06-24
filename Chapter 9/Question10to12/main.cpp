/*
    Question 10.
    Chapter 9, page 334

    file Chrono.cpp
    Defininions of Chrono.h

    Determine the leap year.
*/

#include "Chrono.h"
using namespace Chrono;

int main()
{
    Date today = Date{2023, Month::apr, 10};
    Date mybirthday = Date{2002, Month::jun, 16};

    int y = today.year();
    if (!(leapyear(y))) {
        cout << " Not a leap year!";
    } else {
        cout << "It is a leap year!";
    }

    cout << '\n' <<  today << endl;
    cout << "The number of days since 1st Jan: " << daysSince1stJan(today) << endl;

    Day days = day_of_week(today);
    cout << "Today is " << days << endl;

    cout << "Next workday of today is: " << next_workday(today) << endl;
    cout << "Week of the year is " << weekofYear(today) << endl;
    cout << "Number of days since 1/1/1970: " << daysSince1stJan1970(today) << " days" << endl;
    cout << "How many days since i was born: " << daysBetween(mybirthday, today) << " days" << endl;

}


