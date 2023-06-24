#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
//------------------------------------------------
int main()
{
    fstream readIN {"text.txt"};

    int sum = 0;
    string temp;

    while (getline(readIN, temp)) {
        stringstream ss(temp);

        int num;
        while (ss >> num){
            cout << num;
            sum += num;
        }
    }
    
    cout << "Sum of white-space integer: " <<sum;

}