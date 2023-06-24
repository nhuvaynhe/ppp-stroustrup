#include "std_lib_facilities.h"

void f(const int);

int main()
{
 int n1 = 1;
 const int n2 = 2;

 f(n1);
 f(n2);
 f(3);

 keep_window_open();

 return 0;
}


void f(const int i)
{
 cout << i << endl;
}