#include <iostream>
using namespace std;

/*
	Compute the series and note when the int overflows; the previous value was the largest that fit
*/


int main()
try
{
	int n = 1;
	int m = 2;

	while (n<m) {
			cout << n << '\n';
			int x = n+m;
			n = m;	// drop the lowest number
			m = x;	// add a new highest number
	}

	cout << "the largest Fibonacci number that fits in an int is " << n << '\n';

}
catch (runtime_error e) {	// this code is to produce error messages
	cout << e.what() << '\n';
}
