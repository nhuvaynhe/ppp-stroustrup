//Compare two number

#include <iostream>
using namespace std;

int main()
{
    cout<<"\nEnter two number to compare: \n";
    cout<<"x1: ";
    int val1;
    cin>>val1;

    cout<<"x2: ";
    int val2;
    cin>>val2;

    if (val1 == val2)
        cout<<"\nThose two numbers are equal!";
    else if (val1 > val2)
        cout<<"\nx1 is larger than x2";
    else cout<<"\nx1 is smaller than x2";

    cout<<"\nSum of those numbers: "<<val1 + val2<<'\n';
    
    double a = val1;
    double b = val2;
    cout<<"val1 is equal "<<a/b<<" time val2";

    cout<<"\nProduct of two numbers: "<<val1*val2;
    cout<<"\nDifference between two number: "<<val1-val2<<'\n';
}