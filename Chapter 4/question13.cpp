//Sieve of Eratosthenes

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    vector<int> int_number;
    vector<int> non_prime;
    vector<int> prime;

    int max = 0;
    cout<<"Enter the maximum number: \n";
    cin>>max;

    for (int i = 2; i <= max; ++i){
        int_number.push_back(i);
    }

    for (int j = 0; j <= int_number.size(); ++j){
        if (int_number[j] != 2 && int_number[j] != 3 && int_number[j] != 5 && int_number[j] != 7 &&
            (int_number[j] % 2 == 0 || int_number[j] % 3 == 0 ||int_number[j] % 5 == 0 || int_number[j] % 7 == 0))
            {
                non_prime.push_back(int_number[j]);
            }
        else prime.push_back(int_number[j]);
    }

    for (int x : prime)
    {
        cout<<x<<" ,";
    }
}