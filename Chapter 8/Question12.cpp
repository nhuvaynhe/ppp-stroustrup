/*
	Question 12.
    Chapter 8, page 300
    Date: 05/04/2023
    Improve 'print_until_s()' program.
*/

#include "std_lib_facilities.h"

void print_until_s(vector<string> v, string quit)
{
    for (string s : v){
        if (s == quit) return;
        cout << s << ", ";
    }
}

void print_until_ss(vector<string> v, string quit)
{   
    int quitFound = 0;

    for (string s : v){

        if (s == quit)
            ++quitFound;
        else if (quitFound == 2) 
            return;
        

        cout << s << endl;
    }
}

int main()
{
    vector<string> fruit = {"orange", "broccoli", "carrot", "tomato", "pea", "spinach", "carrot", "tomato", "pea", "spinach"};
    print_until_s(fruit, "spinach");

    cout << " \n \n \n";
    print_until_ss(fruit, "pea");
}