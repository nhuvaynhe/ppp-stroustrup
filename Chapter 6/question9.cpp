//  Write a program that reads digits and composes them into integers.
// Question 9, page 220
// 24/03/2023

#include "std_lib_facilities.h"

class hundred_ten_one {
    public:
        char hundred;
        char ten;
        char one;
        hundred_ten_one(char unit_100, char unit_10, char unit_1)
            :hundred(unit_100), ten(unit_10), one(unit_1) { } 
};

vector<hundred_ten_one> digits;

int main()
{
    char u100, u10, u1;
    cout<<"Enter some digits: \n";
    cin >> u100 >> u10 >> u1;
    hundred_ten_one hro(u100, u10, u1);
    digits.push_back(hro); 

    int unit = digits[0].one - '0';
    int tens = digits[0].ten - '0';
    int hundred = digits[0].hundred - '0';

    if (hundred == 0 && tens == 0){
        cout << unit << " is " << unit << " ones \n";
        return 0;
    }
    else if (hundred == 0){
        cout << tens*10 +unit << " is " << tens << " tens and " << unit << " ones \n";
        return 0;
    }
    else {
        cout << hundred*100 + tens*10 +unit << " is " << hundred << " hundred and " << tens << " tens and " << unit << " ones \n";
        return 0;
    }
}