//Exercise about calculation, page 68

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout<<"Please enter a random number:\n";
    int n;
    cin>>n;
    cout<<"Square of n = "<<n*n
        <<"\nn +2023 = "<<n+2023
        <<'\n'; //Another name for new line in output
    double s = n;
    cout<<"Square root of n = "<<sqrt(s)<<'\n';
}