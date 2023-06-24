/*
    Drill #1.
    Chapter 17, page 623.
    Date: 04/05/2023
*/

#include "std_lib_facilities.h"

//-------------------------------------------------------------------------- 
void print_array10(ostream& os, int* a)
{   
    for (int i=0; i<9; ++i) {
        os << a[i] << ", ";
    }
    os << a[9] << endl;
}
//-------------------------------------------------------------------------- 
void print_array(ostream& os, int* a, int n)
{   
    int last = n-1;
    for (int i=0; i<last; ++i) {
        os << a[i] << ", ";
    }
    os << a[last] << endl;
}

int* getArray(int n)            // creat an array of n element started with 100
{
    int* newInts = new int[n];

    for (int i=0; i<n; ++i) {
        newInts[i] = 100 + i;
    }

    return newInts;
}
//-------------------------------------------------------------------------- 
vector<int*> getVector(int n)
{
    vector<int*> temp;
    int num = 100;

    for (int i=0; i<n; ++i) {
        temp.push_back(new int{num++});
    }

    return temp;
}

void printVector(vector<int*> v)
{
    for (int i=0; i<v.size(); ++i){
        cout << "Int " << i << ": " << *v[i] << "\t\t\t; Address: " << v[i] << endl;
    }
}

void deleteVector(vector<int*> v)
{
    for (int i=0; i<v.size(); ++i){
        delete v[i];
    }
}
//-------------------------------------------------------------------------- 
int main()
{   
    // drill 2
    int* tenInts = getArray(10);
    
    // drill 1
    for (int i=0; i<10; ++i) {
        cout << "Int " << i << ": " << tenInts[i] << "\t\t\t; Address: " << &tenInts[i] << endl;
    }

    // drill 3
    delete[] tenInts;

    // drill 4&5
    cout << "--------------------------------------------------- " << endl;
    int* tenInts2 = new int[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print_array10(cout, tenInts2);
    delete[] tenInts2;

    // drill 6&7
    cout << "--------------------------------------------------- " << endl;
    int* elevenInts = getArray(11);
    print_array(cout, elevenInts, 11);
    delete[] elevenInts;

    // drill 8
    cout << "--------------------------------------------------- " << endl;
    int* twentyInts = getArray(20);
    print_array(cout, twentyInts, 20);
    delete[] twentyInts;

    // drill 10
    cout << "--------------------------------------------------- " << endl;
    vector<int*> tenInts3 = getVector(10);
    printVector(tenInts3);

    cout << "--------------------------------------------------- " << endl;
    vector<int*> elevenInts2 = getVector(11);
    printVector(elevenInts2);

    cout << "--------------------------------------------------- " << endl;
    vector<int*> twentyInts2 = getVector(20);
    printVector(twentyInts2);

}