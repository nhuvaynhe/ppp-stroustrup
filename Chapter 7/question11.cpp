// Read (day-of-the-week, value) pairs
// Question 14, page 170
// This is an updated version
// 01/04/2023

#include "std_lib_facilities.h"

vector<string> uppercaseDay = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
vector<string> lowercaseDay = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
vector<string> abbreviatedDay = {"mon", "tue", "wed", "thurs", "fri", "sat", "sun"};

class DayValue{
public:
    string day;
    double value;
    DayValue (string d, double val) : day(d), value(val) { }
};

vector<DayValue> dayTable;

bool isDay(string inputDay)
{
    vector<string> accepted_day = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday",
                                    "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday",
                                    "mon", "tue", "wed", "thurs", "fri", "sat", "sun"};

    for (int i = 0; i < accepted_day.size(); ++i)
    {
        if (inputDay == accepted_day[i]) return true;

    }
    return false;
}

string convertDay(string day){
    for (int i = 0; i < uppercaseDay.size(); ++i){
        if (day == lowercaseDay[i] || day == abbreviatedDay[i])  {
            day = uppercaseDay[i];
            return day;
        }
    }
    return 0;
}

void getValue(string day, double val){

    string convertedDay = convertDay(day);    // Convert all input to uppercase 

    dayTable.push_back(DayValue(convertedDay, val));
}

int main()
{   
    string inputDay;
    int inputVal;

    cout << "\tEnter Day and its Value"
         << "\n\tEnter 'Stop 0' to stop \n";

    while (cin >> inputDay >> inputVal) {
        
        if (inputDay == "Stop" && inputVal == 0) break;

        if (!(isDay(inputDay))) {
            cerr << "Wrong input \n";    // Check input
        } else getValue(inputDay, inputVal);
    }
    
    if (dayTable.size() == 0) cout << "You haven't inputted any thing!";

    for (int i = 0; i < dayTable.size(); ++i){
        cout << dayTable[i].day <<"\t\t"<< dayTable[i].value <<'\n';
    }
}
