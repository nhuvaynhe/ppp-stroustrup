/*
	Question 3.
    Chapter 8, page 300
    Date: 03/04/2023
    Write the function print out vector.
*/

#include "std_lib_facilities.h"


void Fibonacci(int x, int y, vector<int>& fibo, int n)
{
    fibo.push_back(x);
    fibo.push_back(y);

    for(int i = 0; i <= n - 2; ++i)
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
    int n;

    vector<int> v;

    cin >> x >> y >> n;
    if (x > y) error("x must be lower than y");
    if (n < 3) error("n must larger than 2");
    Fibonacci(x, y, v, n);

    string name = "Fibonacci";
    printVector(v, name);
}