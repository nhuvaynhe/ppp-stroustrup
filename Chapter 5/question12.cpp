// 'Bulls and Cows' game
// Question 12, page 170
// 18/03/2023

// Bull = right number in the right posion
// Cow = right number in the wrong position

#include <iostream>
#include <vector>
using namespace std;

int main()
try
{
    vector<int> four_digits;
    vector<int> digit_of_game = {1, 2, 3, 4};

    int num = 0;
    int ite = 0;
    cout<<"Enter four different digits: \n";

    while (ite < 4 && (cin >> num))   // Beware the order, 'cin' must be behind 'ite'
    {
        if (!cin) throw runtime_error("BAD INPUT! Not a integer");
        if (num > 9) throw runtime_error("BAD INPUT! Not a digit");

        four_digits.push_back(num);
        if (ite != 0){ 
            for (int i = 0; i < ite; ++i){
                if (num == four_digits[i])    // If the lastest value = old value
                {
                    four_digits.erase(four_digits.begin() + ite);   // Delete the lastest value in vector
                    ite = ite -1;
                    cout<<"You enter the number TWICE";
                }
            }
        }
        ++ite;
    }

    cout<<"Your list of numbers is: ";
    for (int x : four_digits)
    {
        cout<<x<< ", ";
    }

    int bull = 0;
    int cow = 0;
    vector<int> different_location = {};   // Save 'not a bull' location

    for (int location = 0; location < four_digits.size(); ++location){
        if (four_digits[location] == digit_of_game[location]){
            ++bull;
        } else different_location.push_back(location);
    }

    for (int y : different_location)
    {
        for (int z : digit_of_game)
        {
            if (four_digits[y] == z) ++cow;
        }
    }

    cout<<"Checking...";
    cout<<"\nCow: "<<cow<<'\t'<<"Bull: "<<bull;
}
catch (exception& e)
{
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "Unexpected error!\n";
    return 2;
}

