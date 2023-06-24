//Calculator +, -, *, /

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string val1 = " ";
    string val2 = " ";
    double sum = 0;
    char math = ' ';

    vector<int> number = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    cout<<"Enter two numbers and an operator [+, -, *, /]: \n";
    cin>> val1 >> math >> val2;
    switch (math)
    {
    case '+':
        sum = val1 + val2;
        cout<<"The sum of "<<val1<<" and "<<val2<<" is equal "<<sum<<'\n';
        break;
    case '-':
        sum = val1 - val2;
        cout<<"The minus of "<<val1<<" and "<<val2<<" is equal "<<sum<<'\n';
        break;
    case '*':
        sum = val1 * val2;
        cout<<"The multiply of "<<val1<<" and "<<val2<<" is equal "<<sum<<'\n';
        break;
    case '/':
        sum = val1 / val2;
        cout<<"The devision of "<<val1<<" and "<<val2<<" is equal "<<sum<<'\n';
        break;
    default:
        cout<<"Wrong input!! \n";
        break;
    }
}