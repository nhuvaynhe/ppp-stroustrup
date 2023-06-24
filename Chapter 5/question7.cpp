// Solving quadratic equation
// Question 7, page 170
// 16/03/2023

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double quadratic_equa(double a, double b, double c)     // Finding the root
{
    vector<double> root = {};
    double delta = b*b - 4*a*c;

    if (delta < 0)
    {
        cerr << "This equation has no roots";
    } else if (delta > 0) {
        double x1 = (-b + sqrt(delta))/(2*a);
        double x2 = (-b - sqrt(delta))/(2*a);
        root.push_back(x1);
        root.push_back(x2);
        cout<<"The equation has two  roots: "<<x1<<" and "<<x2<<'\n';

    }
    else {
        double x = -b/2*a;
        root.push_back(x);
        cout<<"The equation has only one root: "<<x<<'\n';
    }

    for (double x : root){
        cout<<"\nChecking...\n";
        double f = a*x*x + b*x + c;

        if (f > -0.0001 && f < 0.0001)
        {
            cout<<"The root "<<x<<" are plausible \n";
        } else cerr<<"Something wrong with the root "<<x<<"!\n";
    }

    return 0;
}

int main()
{
    double a, b, c = 0;
    cin >> a >> b >> c;
    quadratic_equa(a, b, c);
}