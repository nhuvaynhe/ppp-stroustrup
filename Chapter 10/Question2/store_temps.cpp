/*
    Question 2.
    Chapter 10, page 377.

    store_temps.cpp
*/

#include "std_lib_facilities.h"
#include <fstream>

struct Reading
{   
    char suffix;
    int hour;
    double temperature;
};

vector<Reading> temps;
// Check for duplicate input in hour
bool notDuplicate(int hour)
{
    for (Reading r : temps) {
        if (hour == r.hour) return false;
    }

    return true;
}


int main()
{
    fstream fs("raw_temps.txt");
    if (!fs) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    char suffix;
    int hour;
    double temperature;

    cout << "Enter suffix - hour - temperature" << endl;
    while (cin >> suffix >> hour >>  temperature) {
        if (suffix != 'c' && suffix != 'C'
            && suffix != 'f' && suffix != 'F'){
                error("Wrong suffix!");
            }
        if (hour < 0 || hour > 23) error("Out of range!");
        if (!notDuplicate(hour)) error("Duplicate!");
        if (temperature > 200 || -200 > temperature) error("Out of range!");
        
        temps.push_back(Reading{suffix, hour, temperature});
    }

    for (Reading t : temps)
    {
        fs << t.suffix << '-' << t.hour <<'-'<< t.temperature << endl;
    }

    fs.close();
}