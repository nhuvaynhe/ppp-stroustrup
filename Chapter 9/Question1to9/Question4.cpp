/*  
    Question 4.
    Chapter 9, page 339.
    09/04/2023
    Indent and explain last example of 8.4.
*/

#include "std_lib_facilities.h"

struct X {
    void f(int x){
        // strangely retrun 1 no matter what
        struct Y {
            int f() { return 1; }
            int m;
        };
        int m; 
        m = x; 
        Y m2;
        return f(m2.f()); 
    }

    int m; 
    void g(int m) {
        if (m) 
            f(m+2);
        else {
            g(m+2);
        }
    }

    X() { } void m3() {

    }

    void main() {
        X a;
        a.f(2);
    }
};