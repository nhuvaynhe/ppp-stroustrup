//  Write a program that reads digits and composes them into integers.
// Question 9, page 220
// 24/03/2023
// An improved version

#include "std_lib_facilities.h"

class Number {
    public:
        vector<int> digits;

        int get_vector(char num) {
    int v_num = num - '0';
    if (v_num >= 0) digits.push_back(v_num);
    else error("You can't enter negative number!");
}
        
        
        void print() {
    int i = digits.size() - 1;
    if (i == 2) {
        cout << digits[0] << " hundreds "  
             << digits[1] << " tens "
             << digits[2] << " ones ";
        }
    if (i == 1) {
        cout << digits[0] << " tens "  
             << digits[1] << " ones ";
    }
    if (i == 0) {
        cout << digits[0] << " tens ";  
    }
}
};

int main()
try
{
    cout << "Enter 3 digit of number in order: \n";
    char num;
    Number nu;
    for (int i = 0; i < 3; ++i){
        Number nu;
        cin >> num;
        nu.get_vector(num);
    }
    nu.print();

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