//Set of name-and-value

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    vector<string> sName = {"Test", };
    vector<int> nScore = {0, };

    string student = " ";
    int grade = 0;
    int i = 0;
    int nTest = 1;

    cout<<"Enter the name of the student and his/her grade: ";
    cout<<"\nNOTE: You can enter NoName 0 to stop! \n";
    while (cin >> student >> grade)
    {
        if (student != "NoName"){
            for (int i = 0; i < sName.size(); ++i){
                if (student == sName[i]){
                    cout<<"--> The name "<<student<<" has been enter twice \n";
                    cout<<"Please try again!\n";
                    ++nTest;
                }
            }    
        } else break;

        if (nTest == 1)
        {
            sName.push_back(student);
            nScore.push_back(grade);
        } else {
            nTest = 1;
        }
    }

    for (int j = 1; j < sName.size(); ++j)
    {
        cout<<'\n'<<sName[j]<<'\t'<<nScore[j]<<'\n';
    } 

}