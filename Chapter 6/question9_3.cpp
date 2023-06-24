#include <iostream>
#include <vector>
using namespace std;

class Number {
public:
    int num;
    vector<int> digits;

    Number(int n) {
        num = n;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
    }

    void print() {2
        cout << num << " is ";
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] > 0) {
                cout << digits[i] << " ";
                if (i == 2) {
                    cout << "hundred ";
                } else if (i == 1) {
                    cout << "ten ";
                } else if (i == 0) {
                    cout << "one ";
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int input;
    cout << "Enter a number: ";
    cin >> input;

    Number n(input);
    n.print();

    return 0;
}