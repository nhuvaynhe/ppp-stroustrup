/*
    Try this #1.
    Chapter 18, page 644.
    Date: 07/05/2023.

    Debugging constructors and destructors.
*/

#include <iostream>
#include <vector>
using namespace std;

struct X {                  // simple test class
    int val;

        void out(const string& s, int nv)
            {cerr << this << "->" << s << 
                ": " << val << "(" << nv << ")\n"; }

        X() { out("X()", 0); val = 0; }                     // default constructor

        X(int v) { val =v; out("X(int)", v); }
        
        X(const X& x) { val = x.val; out("X(X&) ", x.val);} // copy constructor

        X& operator=(const X& a)
            { out("X::operator=()", a.val); val=a.val; return *this; }

        ~X() { out("~X()", 0); }                            // destructor
};

X glob(2);      // a global variable

X copy(X a) { return a;}

X copy2(X a) { X aa = a; return aa; }

X& ref_to(X& a) { return a; }

X* make(int i) { X a(i); return new X(a); }

struct XX { X a; X b; };

int main()
{
        cout << "-------------------------------------------------------------------------- " << endl;

    X loc {4};          // local variable

        cout << "-------------------------------------------------------------------------- " << endl;

    X loc2 {loc};       // copy construction

        cout << "-------------------------------------------------------------------------- " << endl;

    loc = X{5};         // copy assignment

        cout << "-------------------------------------------------------------------------- " << endl;

    loc2 = copy(loc);   // call by value and return

        cout << "-------------------------------------------------------------------------- " << endl;

    loc2 = copy2(loc);  

        cout << "-------------------------------------------------------------------------- " << endl;

    X loc3 {6};

        cout << "-------------------------------------------------------------------------- " << endl;

    X& r = ref_to(loc); // call by reference and return

        cout << "-------------------------------------------------------------------------- " << endl;

    delete make(7);

        cout << "-------------------------------------------------------------------------- " << endl;

    delete make(8);

        cout << "-------------------------------------------------------------------------- " << endl;

    vector<X> v(4);     // default values

        cout << "-------------------------------------------------------------------------- " << endl;

    XX loc4;

        cout << "-------------------------------------------------------------------------- " << endl;

    X* p = new X{9};    // and X on the free store

        cout << "-------------------------------------------------------------------------- " << endl;

    delete p;

        cout << "-------------------------------------------------------------------------- " << endl;

    X* pp = new X[5];   // an array of Xs on the free store

        cout << "-------------------------------------------------------------------------- " << endl;

    delete[] pp;

        cout << "\tEND\n " << endl;

}