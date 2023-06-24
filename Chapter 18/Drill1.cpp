/*
    Drill #1.
    Chapter 18, page 663.
    Date: 07/05/2023.

    Array exercise.
*/

#include <iostream> 
using namespace std;

int ga[] = { 1, 2, 4, 8, 16 };

void f(int ar[], int sz)
{
    int la[10];
    int* p = new int[sz];

    for (int i=0; i<sz; ++i) {
        la[i] = ga[i];
        p[i] = ga[i];
    }

    for (int i=0; i<10; ++i) {
        cout << "la[" << i+1 << "] = " << la[i] << endl;
    }
    cout << "--------------------------------------------------------------------------" << endl;
    for (int i=0; i<sz; ++i) {
        cout << "p[" << i+1 << "] = " << p[i] << endl;
    }

    delete[] p;
}

int main()
{   
    f(ga, 5);

    int aa[10];

    for (int index=1; index<11; ++index) {

        aa[index -1] = 1;

        for (int i=1; i<=index; ++i) {
            aa[index -1] *= i;
        }
    }

    cout << "\n\n\tNEW" << endl;

    f(aa, 10);
}