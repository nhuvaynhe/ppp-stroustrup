/*
    Drill #2.
    Chapter 17, page 623.
    Date: 04/05/2023
*/

#include "std_lib_facilities.h"

//-------------------------------------------------------------------------- 
int* getInts(int n)
{   
    int* nInts = new int[n];

    nInts[0] = 1;
    for (int i=1; i<n; ++i){
        nInts[i] = nInts[i-1]*2;
    }

    return nInts;
}
//--------------------------------------------------------------------------
void printInts(int* p, int n)
{
    for (int i=1; i<n; ++i){
        cout << "Int: " << p[i] << "\t;Address: " << &p[i] << endl;
    }
}
//--------------------------------------------------------------------------
int main()
{   
    //drill 1, 2
    int num = 7;
    int* p1 = &num;

    cout << "Int: " << *p1 << "\t;Address: " << p1 << endl;

    // drill 3
    cout << "-----------------------------------------------------------------" <<endl;
    int* p2 = getInts(7);
    printInts(p2, 7);

    // drill 4
    cout << "-----------------------------------------------------------------" <<endl;
    int* p3 = p2;   
    printInts(p3, 7);

    // drill 5
    p2 = p1;

    // drill 6
    p2 = p3;

    // drill 7
    cout << "-----------------------------------------------------------------" <<endl;   
    printInts(p1, 7);

    cout << "-----------------------------------------------------------------" <<endl; 
    printInts(p2, 7);

    // drill 9
	// we haven't allocated anything to the free store, they are all local variables;
	// therefore they are allocated on the stack

    // drill 10
    p1 = getInts(10);

    // drill 11
	int tenInts2[10] = { 10,20,40,80,160,320,640,1280,2560,5120 };
	p2 = tenInts2;

    // drill 12
    for (int i=0; i<10; ++i)
        p2[i] = p1[i];

    // drill 13
    vector<int> v_tenInts = { 1,2,4,8,16,32,64,128,256,512 };
    p1 = &v_tenInts[0];
    vector<int> v_tenInts2 = { 10,20,40,80,160,320,640,1280,2560,5120 };
    p2 = &v_tenInts2[0];

    for (int i=0; i<10; ++i)
        p2[i] = p1[i];
}