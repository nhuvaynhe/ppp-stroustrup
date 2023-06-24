//Solving a quadratic equations.

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    double a, b, c;

    cout<<"This program is used to solve equation: ax^2 +bx +c = 0";
    cout<<"\nPlease enter a, b, c in order: ";
    cin >> a >> b >> c;

    double delta = b*b - 4*a*c;
    double x1, x2;

    if (delta > 0)
    {
        x1 = (-b + sqrt(delta)) / 2*a;
        x2 = (-b - sqrt(delta)) / 2*a;
    } else if (delta == 0){
        x1 = -b / 2*a;
    } else {
        cout<<"This equation has no solution \n";
        return 0;
    }
    
    if (delta == 0)
    {
        cout<<"\nThis equation has only one solution, which equals "<<x1;
    } else cout<<"\nThe root of this equation is "<<x1<<" and "<< x2;
    
}