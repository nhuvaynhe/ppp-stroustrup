/*
    Try this #2.
    Chapter 11, page 382.

    Complete the code fragment above to make it into a program. Try the sug-
    gested input; then type in 
        1234  1234  1234  1234
    Explain the results. Try other inputs to see what happens.
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter four integer: \n";
    int a, b, c ,d;
    cin >> a >> hex >> b >> c >> oct >> d;

    cout << "Result: \n";
    cout << a << '\n' << b << '\n'
         << c << '\n' << d << '\n';
}