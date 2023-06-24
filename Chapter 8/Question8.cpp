/*
	Question 8.
    Chapter 8, page 301
    Date: 04/04/2023
    Compute an index price*weight.
*/

#include "std_lib_facilities.h"

int compute(vector<double> v1, vector<double> v2)
{
    if (v1.size() != v2.size()) error("Both vector must be the same size");

    double sum = 0;
    for (int i = 0; i < v1.size(); ++i){
        sum += v1[i]*v2[i];
    }

    return sum;
}

int main()
{
    vector<double> price = {1, 2, 3.3, 4.6, 44, 67, 6};
    vector<double> weight = {1, 2, 55, 6, 22, 7, 7};

    double index = compute(price, weight);

    cout << "The index is " << index;
}