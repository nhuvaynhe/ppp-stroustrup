/*
    Question 9.
    Chapter 10, page 378.
    15/04/2023

    The sum of all the whitespace-separated integers in a text file.
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdexcept>
using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

int main() {
    int sum = 0, number;
    vector<int> numbers;
    string word;
    ifstream file("text.txt");

    while (file >> word) {
        try {
            number = stoi(word);
        }
        catch (const std::exception &) {
            continue;
        }
        numbers.push_back(number);
    }

    if (file.fail() && !file.eof())
        exit(1);

    for (int x : numbers)
        sum += x;

    cout << sum << "\n";
    keep_window_open();
}