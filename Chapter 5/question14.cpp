// Read (day-of-the-week, value) pairs
// Question 14, page 170
// 18/03/2023

#include <iostream>
#include <vector>
using namespace std;

string check_day(string day)
{
    vector<string> day_full_str = {"Monday", "Tuesday", "Wednesday", 
                                "Thursday", "Friday", "Saturday", "Sunday"};

    vector<string> day_lowercase_str = {"monday", "tuesday", "wednesday", 
                                "thursday", "friday", "saturday", "sunday"};

    vector<string> day_short_str = {"mon", "tue", "wed", "thurs", "fri", "sat", "sun"};
    int test = 0;

    for (int i = 0; i < day_full_str.size(); ++i)
    {
        if (day == day_full_str[i] || day == day_lowercase_str[i] 
            || day == day_short_str[i])
        {   
            day = day_full_str[i];
            ++test;
            return day;
        }
    }

    if (test != 1){
        day = "Error";
        return day;
    }

}

int main()
{   
    vector<string> day_of_week;
    vector<int> day_value;

    string day;
    int value;
    int ite = 0;

    cout<<"Please enter the day-of-the-week and its value: \n";
    while (ite < 7 && (cin >> day >> value))   // Beware the order, 'cin' must be behind 'ite'
    {
        day = check_day(day);
        if (day == "Error") throw runtime_error("NOT A DAY OF A WEEK!!!");

        day_of_week.push_back(day);
        day_value.push_back(value);

        if (ite != 0){ 
            for (int i = 0; i < ite; ++i){
                if (day == day_of_week[i])    // If the lastest value = old value
                {
                    day_of_week.erase(day_of_week.begin() + ite);
                    day_value.erase(day_value.begin() + ite);   // Delete the lastest value in vector
                    ite = ite -1;
                    cout<<"You has entered this day! \n";
                }
            }
        }
        ++ite;
    }

    int sum = 0;
    for (int x : day_value){
        sum += x;
    }

    day_value.push_back(sum);
    day_of_week.push_back("SUM ->");

    cout<<"\nDay"<<'\t'<<"Value"<<'\n';
    cout<<"-------------\n";
    for (int i = 0; i< day_value.size(); ++i){
        cout<<day_of_week[i]<<"    \t";
        cout<<day_value[i]<<'\n';
    }

}
