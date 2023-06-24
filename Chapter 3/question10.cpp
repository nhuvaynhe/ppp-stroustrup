// Write a program that takes an operation followed by two operands and outputs the result.

#include <iostream>
using namespace std;

int main()
{
    string operation = " ";
    double var1;
    double var2;

    cout<<"Please enter an operation followed by two operands: \n ";

    double res = 0;
    while (cin >> operation >> var1 >> var2){

        if (operation == "plus" || operation == "+") res = var1 + var2;
        else if (operation == "mul" || operation == "*") res = var1*var2;
        else if (operation == "minus" || operation == "-") res = var1 - var2;
        else if (operation == "devide" || operation =="/"){
            if (var2 == 0) cout<<"Error! Can not devide to 0";
            else res = var1/var2;
        }
        else cerr<<"Error, please try again! \n";
        cout << var1 << " " << operation << " " << var2 << " = " << res << '\n';
    }
}