/*  
    Question 3.
    Chapter 9, page 339.
    09/04/2023
    Replace 'Name_pairs::print()'
*/

#include "std_lib_facilities.h"

class Name_pairs {
public:
    vector<string> nameSet;
    vector<double> ageSet;

    void read_name();
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
void Name_pairs::read_name()
{   
    string nameIn;
    while (cin >> nameIn){
        if (nameIn == "stop") break;
        if (isName(nameIn)) {
            nameSet.push_back(nameIn);
        } else { 
            cout << "Invalid name!\n";
        }
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
ostream& operator<<(ostream& os, const Name_pairs& np)
{
    for (int i=0; i < np.nameSet.size(); ++i)
    {
        cout << "\t(" << np.nameSet[i] <<','<< np.ageSet[i] << ") \n";
    }

    return os;
}

bool operator==(const Name_pairs np1, const Name_pairs np2)
{
    for (int i=0; i < np1.nameSet.size(); ++i)
    {
        if (!(np1.nameSet[i] == np2.nameSet[i] && np1.ageSet[i] == np2.ageSet[i]))
        {
            return false;
            break;
        }
    }

    return true;
}

bool operator!=(const Name_pairs np1, const Name_pairs np2)
{
    return !(np1 == np2);
}
//-------------------------------------------------------------------
int main()
{
    cout << "Name_pairs set 1\n";
    Name_pairs np1;
    np1.read_name();
    np1.read_age();
    np1.sortName();

    cout << "Name_pairs set 2\n";
    Name_pairs np2;
    np2.read_name();
    np2.read_age();
    np2.sortName();

    cout<<np1;
    cout<<"\n"<<np2;
    if (np1 == np2) cout << "\n\nEqual";
    if (np1 != np2) cout << "\n\nNot equal";
}