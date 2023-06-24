/*
    Question 8.
    Chapter 10, page 378.
    15/04/2023

    The program concatenates the two files.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string file1, file2, file3;

    cout << "Enter the name of the first file:" << endl;
    cin >> file1;

    ifstream f1 {file1};
    if (!f1) {
        cerr << "Can't open the file!";
        return 1;
    }

    cout << "Enter the name of the second file:" << endl;
    cin >> file2;

    ifstream f2 {file2};
    if (!f2) {
        cerr << "Can't open the file!";
        return 1;
    }

    cout << "Enter the name of the second file:" << endl;
    cin >> file3;

    ofstream f3 {file3};
    if (!f3) {
        cerr << "Can't open the file!";
        return 1;
    }

    // Write data from file 1 & file 2 to "concatenates" file
    string data1;
    string data2;
    while (getline(f1, data1) && getline(f2, data2)) {
        f3 << data1 << '\n' << data2 << endl;
    }
}