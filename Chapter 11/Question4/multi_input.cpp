/*
    Question 4.
    Chapter 11, page 409.
    Date: 19/04/2023

    prompts the user to enter several integers in any combination of octal, decimal, 
    or hexadecimal, using the 0 and 0x base suffixes; interprets the numbers correctly;
    and converts them to decimal form. 
*/

#include <iostream>
#include <vector>
#include <sstream>
#include<iomanip>
using namespace std;

//-------------------------------------------------------------------------- 
vector<int> hexa;
vector<int> octal;
vector<int> deci;
//-------------------------------------------------------------------------- 
void convert(string s)
{   
    int num;

    if (s[0] == '0' && s[1] == 'x') {
        num = stoi(s, nullptr, 16);
        hexa.push_back(num);

    } else if (s[0] == '0') {
        num = stoi(s, nullptr, 8);
        octal.push_back(num);

    } else {
        num = stoi(s);
        deci.push_back(num);   
    }
}
//-------------------------------------------------------------------------- 
void print() 
{
    for (int x : hexa) {
        cout << showbase << dec;
        cout << hex <<  x << '\t' << "hexadecimal" << '\t'
             << "converted to" << '\t' << dec << x << endl;
    }
        
    for (int x : deci)
        cout << x << '\t'<< "decimal" << "\t\t"
             << "converted to" << '\t' << x << endl;
    
    for (int x : octal) {
        cout << showbase << dec;
        cout << oct << x << '\t' << "octal" << "\t\t"
             << "converted to" << '\t' << dec << x << endl;
    }
}
//-------------------------------------------------------------------------- 
int main()
{   
    cout << "Enter several integers: "
         << "\n\tYou can input it in any combination of octal, decimal or hexadecimal."
         << "\n\tNote: 0 and 0x base suffixes for octal and hexa" << endl;
    
    string numIn;
    getline(cin, numIn);

    stringstream ss {numIn};
    vector<string> store;
    for (string num; ss >> num; )
        store.push_back(num);
    
    for (string s : store)
        convert(s);

    print();
}