#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    vector<int> dif = {50};
    char x;
    while (cin >> x) {
        for (int i = 0; i < dif.size(); ++i) {
            if (x == 'c') {
                cout << "Done game!!!\n";
                cout << "Your number is " << dif[i] << "\n";
            } else if (x == 'l') {
                cout << "You are thinking " << dif[i]/2 << "?\n";
                dif.push_back(dif[i]/2);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (x == 'h') {
                cout << "You are thinking " << dif[i]*1.5 << "?\n";
                dif.push_back(dif[i]*1.5);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cout << "Wrong input!!! Please enter 'c', 'l', or 'h'.\n";
            }
        }
    }
    return 0;
}
