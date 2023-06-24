//This is used to convert yen, euros and pounds to dollars.
//Rate based on the web.

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string currency = " ";
    double money = 1;

    constexpr double yen_to_dollar = 0.0074;
    constexpr double pound_to_dollar = 1.2;
    constexpr double euro_to_dollar = 1.07;

    cout<<"Please enter the amount of money and its currency (yen/ pound/ euro): \n";
    cin>>money>>currency;

    if (currency == "yen")
         cout<<money<<" yen = "<<money*yen_to_dollar<<" dollar\n";
    else if (currency == "pound")  
         cout<<money<<" pound = "<<money*pound_to_dollar<<" dollar\n";    
    else if (currency == "euro")  
         cout<<money<<" euro = "<<money*euro_to_dollar<<" dollar\n";
    else
         cout<<"Sorry, we have no data about "<<currency<<'\n';
}