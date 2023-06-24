// Drill 3
// Chapter 8, page 298
// 03/04/2023

#include "std_lib_facilities.h"

namespace X {
    int var;
    void print(){
        cout <<"X = "<<var<<'\n';
    }
}

namespace Y {
    int var;
    void print(){
        cout <<"Y = "<<var<<'\n';
    }
}

namespace Z {
    int var;
    void print(){
        cout <<"Z = "<<var<<'\n';
    }
}

int main()
{
    X::var = 7;
    X::print();

    using namespace Y;
    var = 9;
    print();

    {
        using Z::var;
        using Z::print;
        var = 11;
        print();
    }

    print();
    X::print();
}