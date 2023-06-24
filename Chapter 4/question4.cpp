//Guessing game

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string guess = " ";
    int guess_max = 100;
    int guess_min = 1;
    int ite = 0;
    
    cout<<"Think about a number between 1 and 100\n";
    while (guess_max != guess_min && ite < 7){
        cout<<"Is your number larger than or equal "
            <<(guess_max +guess_min +1)/2<<"? [Y/N]: ";
        cin >> guess;
        if (guess == "Y"){
            guess_min = (guess_max +guess_min)/2;
            cout<<guess_max<<'\n';
            cout<<guess_min<<'\n';
            ++ite;
        }
        else if (guess == "N"){
            guess_max = (guess_max +guess_min)/2;
            cout<<guess_max<<'\n';
            cout<<guess_min<<'\n';
            ++ite;
        }
        else{
            cerr<<"Wrong input!!! \n";
            return 0;
        } 
    }
    
    cout<<"Is your number even? [Y/N]: ";
    cin>>guess;
    if (guess == "Y"){
        cout<<"I guess the number you are thinking is: "<<guess_min;
    }
    else if (guess == "N"){
        cout<<"I guess the number you are thinking is: "<<guess_max;
    }
    else cerr<<"Wrong input!!! \n";
    
}