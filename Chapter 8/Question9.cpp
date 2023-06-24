/*
	Question 9.
    Chapter 8, page 301
    Date: 04/04/2023
    Return the largest element in vector.
*/

#include "std_lib_facilities.h"

double maxv(vector<double> v)
{
    if (v.size() == 0) cout << "Empty vector!";

    double max = 0;
    for (double x : v){
        if (x > max) max = x; 
    }

    return max;
}

int main()
{
    vector<double> v = {1, 2, 55, 3, 6, 44, 111};

    cout << "Max element is " << maxv(v);
}

