/*
    Drill #1.
    Chapter 18, page 663.
    Date: 07/05/2023.

    Vector exercise.
*/

#include <iostream> 
#include <vector>
using namespace std;

vector<int> gv;

void getInts(vector<int>& v)
{   
    int num = 1;
    v.push_back(num);

    for (int i=1; i<10; ++i){
        num += num;    
        v.push_back(num);
    }
}

void f(vector<int> v)
{
    vector<int> lv;
    vector<int> lv2 = v;

    for (int i=0; i<gv.size(); ++i) {
        lv.push_back(gv[i]);
    }

    for (int i : lv)
        cout << i << "; ";
    cout << '\n';
    for (int i : lv2)
        cout << i << "; ";
}

int main()
{
    getInts(gv);
    f(gv);

    vector<int> vv;

    for (int index=0; index<10; ++index) {
        int num = 1;

        for (int i=1; i<=index+1; ++i) {
            num *= i;
        }
        vv.push_back(num);
    }

    cout << "\t\n vv print" << endl;
    f(vv);
}