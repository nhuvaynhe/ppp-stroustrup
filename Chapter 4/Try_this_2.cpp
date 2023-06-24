//This program is used to convert pounds, euros, yens, VND to dollars

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    constexpr double yen_to_dollar = 0.0074;
    constexpr double pound_to_dollar = 1.2;
    constexpr double euro_to_dollar = 1.07;
    constexpr double vnd_to_dollar = 0.000042;

    double money = 1;
    char currency = ' ';

    cout<<"Please enter the amount of money and its currency (y/ p/ e/ v): \n";
    cin>>money>>currency;

    switch (currency){
    case 'e':
        cout<<money<<" euro = "<<money*euro_to_dollar<<" dollar\n";
        break;
    case 'y':
        cout<<money<<" yen = "<<money*yen_to_dollar<<" dollar\n";
        break;
    case 'p':
        cout<<money<<" pound = "<<money*pound_to_dollar<<" dollar\n";
        break;
    case 'v':
        cout<<money<<" vnd = "<<money*vnd_to_dollar<<" dollar\n";
        break;
    default:
        cout<<"Sorry, we have no date about"<<currency<<'\n';
        break;
    }
}

