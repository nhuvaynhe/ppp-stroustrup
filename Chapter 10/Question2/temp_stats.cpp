/*
    Question 3.
    Chapter 10, page 377.

    temp_stats.cpp
    input and calculate mean & median
*/

#include "std_lib_facilities.h"
#include <fstream>

struct Reading
{   
    char suffix;
    int hour;
    double temperature;
};

istream& operator>>(istream& is, Reading& read)
{
    int h;
    double t;
    char suffix;
    char space;
    is >> suffix >> space >> h >> space >> t;
    if (!is) return is;
    if (space != '-') {
        is.clear(ios_base::failbit);
        return is;
    }
    if (suffix != 'c' && suffix != 'C'
        && suffix != 'f' && suffix != 'F'){
            error("Wrong suffix!");
    }

    read = Reading{suffix, h, t};
    return is;
}

double getMedian(vector<Reading>& temp)
{   
    int mid = ceil(temp.size()/2);       // Uneven vector size
    if (temp.size() % 2 != 0) return temp[mid].temperature;   
    else return (temp[mid].temperature + temp[mid-1].temperature)/2;
}

void Fconvert(vector<Reading>& temp)
{
    for (Reading& t : temp)     // Remember to use '&', if not the value will not change
    {
        if (t.suffix == 'c' || t.suffix == 'C') {
            t.temperature = t.temperature*(9/5) + 32;
        }
    }
}

int main()
{
    fstream fs("raw_temps.txt");

    vector<Reading> temp_records;
    for (Reading temp; fs >> temp; ) {
        temp_records.push_back(temp);
    }
    
    for (Reading t : temp_records){
        cout << t.temperature << endl;
    }
    cout << "-----------------------------------------------" << endl;
    Fconvert(temp_records);
    for (Reading t : temp_records){
        cout << t.temperature << endl;
    }  

    int hour = 0;
    double sum_temps = 0;
    for (Reading temp : temp_records)
    {
        ++hour;
        sum_temps += temp.temperature;
    }

    cout << "Mean temperature: " << sum_temps/hour << endl;
    cout << "Median temperature: " << getMedian(temp_records);
    fs.close();
}