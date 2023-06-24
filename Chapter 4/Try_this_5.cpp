//Multiplication operation

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x = 1;
    int sum = 0;

    cout<<"Please enter a number: :";
    cin>>x;

    for (int i=0; i<x; ++i){
        sum = sum + x;
    }
     
    cout<<sum;
    
}