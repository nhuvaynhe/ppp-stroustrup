/*
	Question 4.
    Chapter 8, page 300
    Date: 03/04/2023
    Find the maximum integer
*/

#include "std_lib_facilities.h"


void Fibonacci(int x, int y, vector<int>& fibo)
{
    fibo.push_back(x);
    fibo.push_back(y);

    while (x < y)
    {
        int sum{0};
        sum = x + y;
        fibo.push_back(sum);

        x = y;
        y = sum;
    }
}

void printVector(vector<int>& v, string name)
{   
    if (v.size() == 0) cout << "Empty vector";
    cout << name << '\n';
    for (int i = 0; i < v.size(); ++i){
        if ( i == v.size() - 1) cout << v[i];
        else cout << v[i] <<", ";
    }
}

int main()
{
    int x;
    int y;

    vector<int> v;

    cin >> x >> y;
    if (x > y) error("x must be lower than y");
    Fibonacci(x, y, v);

    string name = "Fibonacci";
    printVector(v, name);
}