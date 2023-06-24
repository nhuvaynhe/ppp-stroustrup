//Finding if the number is odd or even

#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter random number: ";
    int num;
    cin >> num;

    if (num % 2 == 0){
        cout<<"It is an even number";
    }
    else{
        cout<<"It is a odd number";
    }
}