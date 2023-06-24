#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const string ex_bad_number_msg = "The number of values to sum must be 1 or greater!";
const string ex_bounds_msg = "You asked to sum more elements than those supplied!";
const string ex_bad_input_msg = "You entered something that's not an integer!";
const string ex_sum_overflow_msg = "The sum cannot be represented with an int type!";

int sum_of_N(int N, const vector<int>& elements)
// Return the sum of the N first elements of vector elements
// pre-condition:   the vector has to have at least N elements
{
    if (N > int(elements.size())) throw runtime_error(ex_bounds_msg);

    int sum = 0;

    for (int i = 0; i < N; ++i) {
        // If we add a positive number to the sum and it becomes less than before, or
        // if we add a negative and sum gets greater, an overflow has happened
        if (elements[i] >= 0 && sum + elements[i] < sum) throw runtime_error(ex_sum_overflow_msg);
        if (elements[i] < 0 && sum + elements[i] > sum) throw runtime_error(ex_sum_overflow_msg);
        sum += elements[i];
    }

    return sum;
}

int main()
try
{
    vector<int> elements;
    int N = 0;

    cout << "Please enter the number of values you want to sum: ";
    cin >> N;
    if (!cin) throw runtime_error(ex_bad_input_msg);
    if (N < 1) throw runtime_error(ex_bad_number_msg);

    cout << "Please enter some integers (press '|' to stop); ";
    int element;
    while (cin >> element)
        elements.push_back(element);

    if (cin.eof()) {
        cout << "Bye, bye!\n";
    }
    else {
        cin.clear();
        char end = ' ';
        cin >> end;
        if (end != '|') {
            throw runtime_error(ex_bad_input_msg);
        }
        else {
            int sum = sum_of_N(N, elements);
            cout << "The sum of the first " << N << " numbers ( ";
            // If sum_of_N hasn't throw, we ca do this:
            for (int i = 0; i < N; ++i)
                cout << elements[i] << ' ';
            cout << ") is " << sum << ".\n";
        }
    }
}        

catch (exception& e)
{
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "Unexpected error!\n";
    return 2;
}