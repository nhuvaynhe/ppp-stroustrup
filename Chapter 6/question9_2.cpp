//  Write a program that reads digits and composes them into integers.
// Question 9, page 220
// 24/03/2023
// An improved version

#include "std_lib_facilities.h"

class Number {
    private: 
        vector<int> digits;                         // Put the vector in private so that we can
    public:                                         // use it for all the member function
        void add_vector(char num);
        void printVector();
};
 
void Number::add_vector(char num) {                 // Put the input back to vector
    int v_num = num - '0';
    if (v_num >= 0) digits.push_back(v_num);
    else error("You can't enter negative number!");
}

void Number::printVector() {                         // Print out the result
    cout << "Your number is ";
    int i = digits.size() - 1;
    if (i == 2) {
        int hun = digits[0];
        int tn = digits[1];
        int unit = digits[2]; 

        cout << hun*100 + tn*10 + unit << " with "
             << hun << " hundreds "  
             << tn << " tens "
             << unit << " ones ";
        }
    else if (i == 1) {
        int tn = digits[0];
        int unit = digits[1]; 

        cout << tn*10 + unit << " with "
             << tn << " tens "  
             << unit << " ones ";
    }
    else if (i == 0) {
        int unit = digits[0];

        cout << unit << " with "
             << digits[0] << " ones ";  
    }
    else  {
        cerr << "\n!!! You does not enter any number !!! ";
    }
}
//-----------------------------------------------------------------
int main()
try
{
    cout << "Enter 3 digit of number in order: \n"
         << "Enter '=' to stop the program \n";
    char num;
    Number nu;
    for (int i = 0; i < 3; ++i){
        cin >> num;
        if (num == '=') break;
        nu.add_vector(num);
    }
    nu.printVector();

    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}