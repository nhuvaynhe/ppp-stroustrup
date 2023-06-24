/*
    Question 9.
    Chapter 17, page 624.
    Date: 04/05/2023
 
    Which way does the stack grow: up (toward higher addresses) or down (to-
    ward lower addresses)? Which way does the free store initially grow (that 
    is, before you use delete)? Write a program to determine the answers.
*/

#include <iostream>
using namespace std;

int main()
{
    int num1 = 1;
    int num2 = 1;
    int num3 = 1;
    int num4 = 1;
    int num5 = 1;
    cout << &num1 << "; " << &num2 << "; " << &num3 
         << "; " << &num4 << "; " << &num5 << endl;
    
    if (&num5 - &num1 > 0)
        cout << "stack grows up" << endl;
    else    
        cout << "stack grows down" << endl;

    cout << "\n-------------------------------------------------------------------------- " << endl;
    double dub1 = 1;
    double dub2 = 1;
    double dub3 = 1;
    double dub4 = 1;
    double dub5 = 1;
    cout << &dub1 << "; " << &dub2 << "; " << &dub3 
         << "; " << &dub4 << "; " << &dub5 << endl;
    
    if (&dub5 - &dub1 > 0)
        cout << "stack grows up" << endl;
    else    
        cout << "stack grows down" << endl;

    cout << "\n-------------------------------------------------------------------------- " << endl;
    int* p_num1 = new int(10);
    int* p_num2 = new int(12);
    int* p_num3 = new int(14);
    int* p_num4 = new int(16);
    int* p_num5 = new int(18);
    cout << p_num1 << "; " << p_num2 << "; " << p_num3
         << "; " << p_num4 << "; " <<p_num4 << endl;
    
    if (p_num5 - p_num1 > 0)
        cout << "stack grows up" << endl;
    else    
        cout << "stack grows down" << endl;

    cout << "\n-------------------------------------------------------------------------- " << endl;
    double* p_dub1 = new double(1.1);
    double* p_dub2 = new double(2.2);
    double* p_dub3 = new double(4.4);
    double* p_dub4 = new double(6.6);
    double* p_dub5 = new double(8.8);
    cout << p_dub1 << "; " << p_dub2 << "; " << p_dub3
         << "; " << p_dub4 << "; " <<p_dub5 << endl;
    
    if (p_dub5 - p_dub1 > 0)
        cout << "stack grows up" << endl;
    else    
        cout << "stack grows down" << endl;

    cout << "\n-------------------------------------------------------------------------- " << endl;
    char* p_char1 = new char('a');
    char* p_char2 = new char('b');
    char* p_char3 = new char('c');
    char* p_char4 = new char('d');
    char* p_char5 = new char('e');
    cout << p_char1 << "; " << p_char2 << "; " << p_char3
         << "; " << p_char4 << "; " <<p_char5 << endl;
    
    if (p_char5 - p_char1 > 0)
        cout << "stack grows up" << endl;
    else    
        cout << "stack grows down" << endl;
    

}