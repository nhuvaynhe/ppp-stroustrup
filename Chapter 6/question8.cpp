// Redo the “Bulls and Cows” game from exercise 12 in Chapter 5 to use 
// four letters rather than four digits.
// Question 8, page 219
// 24/03/2023

#include "std_lib_facilities.h"

vector<char> solution = {'a', 'b', 'c', 'd'};
vector<char> user_guess;

int main()
try
{
    char guess;
    int ite = 0;

    cout <<"This is 'Bull & Cow' game \n"
         << "\t- Bull = right letter in the right posion \n"
         << "\t- Cow = right letter in the wrong position \n"
         << "Please enter your 4 letters guess. ";
    while ((ite<4) && (cin>>guess)){
        if (!(guess >= 'a' && guess <='z')) error("You can only enter letter 'a' to 'z'");
        if (!cin) error("Bad input!");
        user_guess.push_back(guess);
        ++ite;
    }

    int bull = 0;
    int cow = 0;
    vector<int> different_location = {};   // Save 'not a bull' location

    for (int location = 0; location < solution.size(); ++location){
        if (solution[location] == user_guess[location]){
            ++bull;
        } else different_location.push_back(location);
    }

    for (int y : different_location)
    {
        for (int z : solution)
        {
            if (user_guess[y] == z) ++cow;
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