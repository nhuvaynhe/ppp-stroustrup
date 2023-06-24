// Store a series of N integer and calculate the sum
// Question 8, page 170
// 16/03/2023

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
try
{
    vector<int> nSeries = {};
    int num;
    int ite = 0;    // First N number
    int sum = 0;   

    cout<<"Please enter N integer you want to calculate: \n";
    cin >> ite;
    if (!cin) throw runtime_error("BAD INPUT!");
    if (ite < 1) throw runtime_error("BAD INPUT!");

    cout<<"Please enter the series of integer (press '|' to stop)\n";
    while (cin >> num)
    {
        nSeries.push_back(num);
    }

    if (ite > nSeries.size()) // Check condition
    {
        cerr<<"It's larger than the series size!!!\n";
        return 0;
    }

    for (int i = 0; i < ite; ++i)   //Calculate the sum
    {
        sum += nSeries[i];
    }
    
    cout<<"The sum of "<<ite<<" integers is "<<sum;
}
catch (exception& e)
{
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "Unexpected error!\n";
    return 2;
}