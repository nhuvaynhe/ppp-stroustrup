/*
	Question 11.
    Chapter 8, page 301
    Date: 04/04/2023
    Smallest and largest elements in vector. Also the mean and median.
*/

#include "std_lib_facilities.h"

double minmax(vector<double> v, string m)
{
    if (v.size() == 0) cout << "Empty vector!";

    double result = v[0];
    for (double x : v){
        if (m == "max" && x > result) result = x; 
        else if (m == "min" && result > x) result = x;
    }

    return result;
}

double meanV(vector<double> v)
{
    if (v.size() == 0) cout << "Empty vector!";

    double sum = 0;
    for (double x : v)
    {
        sum += x;
    }

    return sum/v.size();

}

double medianV(vector<double> v)
{
    if (v.size()%2 != 0) {
        int i = v.size()/2;
        return v[i];
    } else {
        int i = v.size()/2;
        return (v[i] + v[i-1])/2;
    }
}

int main()
{
    vector<double> v = {44, 55, 3, 6, 44, 111, 9};

    double min = minmax(v, "min");
    double max = minmax(v, "max");
    double mean = meanV(v);
    double median = medianV(v);
    
    cout << min <<"  "<< max <<"  "
         << mean <<"  "<< median;

}
