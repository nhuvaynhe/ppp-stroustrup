//Finding the prime number

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    vector<int> prime_number = {2, };

    vector<int> test = {}; 
    int val = 0;
    int max = 0;

    cout<<"Enter the max number: ";
    cin>>max;

    for (int i = 3; i<= max; ++i){
        for (int j = 2; j<i; ++j){
            test.push_back(j);
        }

        for (int x : test){
            if (i % x == 0){
                val += 1;
            }
        }

        if (val == 0){
            prime_number.push_back(i);
        }

        val = 0;               // Set val = 0 for the next loop
        test.clear();          // Clear all the elements in the vector
    }
    for (int z : prime_number){
        cout<<z<<", ";
    }

    if (prime[0] == prime_number[0] && prime[1] == prime_number[1]){
        cout<<"\nThis is a good answer!!!";
    }
}