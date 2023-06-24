/*
    Try this #4.
    Chapter 11, page 388.

    Make a simple table including the last name, first name, telephone number, 
    and email address for yourself and at least five of your friends. Experiment 
    with different field widths until you are satisfied that the table is well presented.
*/

#include <iostream>
#include <vector>
#include<iomanip>
#include<math.h>
using namespace std;

vector<string> firstName;

void getString(vector<string>& v_string, string statement)
{
    string ss;
    int size = firstName.size();

    cout << "Enter " << size << " numbers of " << statement << '\n';
    for (int i=0; i < size; ++i){
        cin >> ss;

        v_string.push_back(ss);
    }

}

int main()
{
    cout << "Enter first name: \n";
    string first_name;
    while (cin >> first_name){
        if (first_name == "stop") break;
    
        firstName.push_back(first_name);
    }

    vector<string> lastName;
    getString(lastName, "last name");

    vector<string> phoneNumber;
    getString(phoneNumber, "phone number");

    vector<string> emailAdress;
    getString(emailAdress, "email adress");

    int size = firstName.size();
    for (int i=0; i < size; ++i)
    {   
        cout << setw(7) << firstName[i] << '|' 
             << setw(7) << lastName[i] << '|'
             << setw(11) << phoneNumber[i] << '|' 
             << setw(12) << emailAdress[i] << "@gmail.com" << endl;
    }
}   