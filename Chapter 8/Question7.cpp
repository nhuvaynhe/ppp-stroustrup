/*
	Question 7.
    Chapter 8, page 301
    Date: 04/04/2023
    Name - age vector, and then sorted name.
*/

#include "std_lib_facilities.h"

bool isRepeated(string sName)
{
    if (name.size() == 0) return false;

    for (int i = 0; i < name.size(); ++i)
    {
        if (sName == name[i]) return true;
    }

    return false; 
}

void sortedVector(vector<string>& v1, vector<int>& v2)
{
    vector<string> V1copy = v1;
    vector<int> V2copy = v2;

    sort(v1.begin(), v1.end());

    for (int i = 0; i < v1.size(); ++i){
        for (int j = 0; j < v1.size(); ++j)
        {
            if (V1copy[i] == v1[j]){
                v2[j] = V2copy[i];
            }
        }
    }
}


void printVector(vector<string>& v1, vector<int>& v2)
{   
    if (v1.size() == 0 || v2.size() == 0) cout << "Empty vector";

    cout << "\n";
    for (int i = 0; i < v1.size(); ++i){
        cout << v1[i] <<'\t'<< v2[i] <<'\n';
    }
}


int main()
{
    vector<string> name;
    vector<int> age;

    string inputName;
    int inputAge;

    int ite = 0;
    
    cout << "Enter the name of five people: \n";
    while ((ite < 5) && (cin >> inputName))
    {
        if (!cin) error("Wrong input!");
        if (isRepeated(inputName)) error("You input the name TWICE!");

        name.push_back(inputName);
        ++ite;
    }

    cout << "Enter the name of five people: \n";
    ite = 0;
    while ((ite < 5) && (cin >> inputAge))
    {
        if (!cin) error("Wrong input!");
        age.push_back(inputAge);
        ++ite;
    }

    sortedVector(name, age);
    printVector(name, age);
    
}