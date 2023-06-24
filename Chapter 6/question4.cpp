// class Name_value that holds a string and a value
// Question 4, page 218
// 23/03/2023

#include "std_lib_facilities.h"

class Name_value {
    public:
        string name;
        int value;
        Name_value(string n, int v) : name(n), value(v) {}
};

int main()
{
    vector<Name_value> myclass;
    
    string student;
    int score;
    Name_value MYclass(student, score);

    while (student != "NoName" && score != 0){
        cout << "Please enter student name and his/her score: ";
        cin >> student >> score;
        Name_value MYclass(student, score);
        myclass.push_back(MYclass);
    }

    for (int i = 0; i < myclass.size(); ++i){
        cout <<myclass[i].name <<'\t'<<myclass[i].value<<'\n';
    }
}