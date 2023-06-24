/*
    Question 6.
    Chapter 17, page 624.
    Date: 04/05/2023

    This chapter does not say what happens when you run out of memory 
    using new. That’s called memory exhaustion. Find out what happens. You have 
    two obvious alternatives: look for documentation, or write a program with 
    an  infinite  loop that  allocates  but  never deallocates. Try both. Approxi-
    mately how much memory did you manage to allocate before failing?
*/

#include <iostream>
using namespace std;

int main()
{
    for (int i=0; i < 150000000; ++i)
    {
        double* num = new double[2000];
        *num = i * 2.5;

        cout << i << '\t' << ";\t" << *num << endl;
    }

    return 0;
}