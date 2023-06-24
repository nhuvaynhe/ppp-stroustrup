//This program is used to compute avarage and median

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    double median = 0;
    vector<int> temper = {30, 35, 38, 40};

    int size = temper.size();

    if (size % 2 == 0){
        median = (temper[temper.size()/2-1] + temper[temper.size()/2])/2;
    }
    else median = temper[temper.size()/2];

    cout<<median;
}

