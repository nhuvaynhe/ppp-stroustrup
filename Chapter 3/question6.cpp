//Arrange value in order

#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter three integer: \n";
    cout<<"X1: ";
    int x1;
    cin>>x1;

    cout<<"\nX2: ";
    int x2;
    cin>>x2;

    cout<<"\nX3: ";
    int x3;
    cin>>x3;

    if (x1 == x2 == x3)
        cout<<"The order is: "<<x1<<", "<<x2<<", "<<x3;

    else if (x1 >= x2 & x1 >= x3)
        if (x2 >= x3)
             cout<<"The order is: "<<x3<<", "<<x2<<", "<<x1;
        else 
             cout<<"The order is: "<<x2<<", "<<x3<<", "<<x1;

    else if (x2 >= x1 & x2 >= x3)
        if (x1 >= x3)
             cout<<"The order is: "<<x3<<", "<<x1<<", "<<x2;
        else 
             cout<<"The order is: "<<x1<<", "<<x3<<", "<<x2;
    
    else if (x3 >=x1 & x3 >=x2)
        if (x1 >= x2)
             cout<<"The order is: "<<x2<<", "<<x1<<", "<<x3;
        else 
             cout<<"The order is: "<<x1<<", "<<x2<<", "<<x3;
}