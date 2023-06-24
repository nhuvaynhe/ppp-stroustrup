//Grain of rice

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int location = 1;
    double num_of_rice = 1;
    double sum = 1;

    char answer = ' ';

    cout<<"\nYou are at the square "<<location<<" . You have "
        <<num_of_rice<<" grain of rice. \nAnd you total rice is "
        <<sum<<" grain. \n"
        <<"Do you wanna take the next square? [Y/N]: ";

    while (cin>>answer)
    {
        if (answer == 'Y'){
            ++location;
            num_of_rice *= 2;
            sum = sum + num_of_rice;
        }
        else if (answer == 'N'){
            break;
        }
        else cerr<<"Wrong answer!! \n";
    
        cout<<"\nYou are at the square "<<location<<" . You have "
            <<num_of_rice<<" grain of rice. \nAnd you total rice is "
            <<sum<<" grain. \n"
            <<"Do you wanna take the next square? [Y/N]: ";
    }

}