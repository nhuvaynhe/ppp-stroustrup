/*
    Try this #2.
    Chapter 18, page 646.
    Date: 07/05/2023.

    Make a version of this vector that is complete enough to compile and see 
    what error message your compiler produces for v[3]=x;.
*/

#include <iostream> 
using namespace std;

class vector {
    int sz;
    double* elem;
public:
    vector(int s)                               // constructor
        : sz{s}, elem{new double[s]}            // alllocates memory
    {
        for (int i=0; i<sz; ++i) elem[i] =0.0;      //initialize
    }

    vector(initializer_list<double> lst)        // initializer-list constructor
        : sz{lst.size()}, elem{new double[sz]}  // uninitialized memory 
    {                                           // for elements
        copy(lst.begin(), lst.end(), elem);     // initialize (using std::copy())
    }

    ~vector()                                   // destructor
        { delete[] elem; }                      // deallocates memory

    int size() { return sz; }

    double& operator[](int n) { return elem[n]; }    // return reference 
    double operator[](int n) const;
};

void ff(const vector& cv, vector& v)
{
    double d = cv[1];
    
    double d2 = v[1];
    v[1] = 2.0;
}

int main()
{
    vector v(10);
    
    for(int i=0; i<v.size(); ++i)
    {
        v[i] = i;
        cout << v[i];
    }
}