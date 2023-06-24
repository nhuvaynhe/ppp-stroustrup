/*  
    Question 2.
    Chapter 9, page 339.
    09/04/2023
    Design and implement a Name_pairs class
*/

#include "std_lib_facilities.h"

class Name_pairs {
public:
    vector<string> nameSet;
    vector<double> ageSet;

    void read_name(string name);
    void read_age();

    void print();
    void sortName();
    bool isName(string name);        // check whether its a name or not
private:
    string name;
    double age;
};
//-------------------------------------------------------------------
bool Name_pairs::isName(string nameIn)
{
    for (char c : nameIn) {
        if (!isalpha(c)) return false;
    }

    return true;
}
//-------------------------------------------------------------------
void Name_pairs::read_name(string nameIn)
{   
    if (isName(nameIn)) {
        nameSet.push_back(nameIn);
    } else { 
        cout << "Invalid name!\n";
    }
}

void Name_pairs::read_age()
{   
    for (string s : nameSet)
    {
        cout << "Please enter the age of "<< s <<": \n";
        cin >> age;
        ageSet.push_back(age);
    }
}
//-------------------------------------------------------------------
void Name_pairs::sortName()
{   
    vector<string> nameCopy = nameSet;;
    vector<double> ageCopy = ageSet;

    sort(nameSet.begin(), nameSet.end());

    for (int i = 0; i < nameSet.size(); ++i){
        for (int j = 0; j < ageSet.size(); ++j)
        {
            if (nameCopy[i] == nameSet[j]){
                ageSet[j] = ageCopy[i];
            }
        }
    }

}
//-------------------------------------------------------------------
void Name_pairs::print()
{
    for (int i=0; i < nameSet.size(); ++i)
    {
        cout << "\t(" << nameSet[i] <<','<< ageSet[i] << ") \n";
    }
}
//-------------------------------------------------------------------
int main()
{
    cout << "Input the name of the person \n";
    string name;
    Name_pairs np;

    while (cin >> name){
        if (name == "stop") break;
        np.read_name(name);
    }

    np.read_age();

    np.sortName();
    np.print();
}