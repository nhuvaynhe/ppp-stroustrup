/*
    Question 9.
    Chapter 9, page 339.
    07/04/2023
    Design and implement a 'Book' class.
    Design and implement a 'Patron' class.
*/

#include "PatronClass.h"

void Patron::set_fee()
{   
    cout << "Input the fee: "<<endl;
    cin >> libfee;
    Owned = true;
}

bool is_Owned(Patron p)
{
    if (p.get_fee() > 0) {
        cout << "\nThe user's name " << p.getName() << " owned " << p.get_fee() << " dollar!" <<endl;
        return true;
    } else {
        cout << "\nThe user's name " << p.getName() << "has no fee " << endl;
        return false;
    }
}

ostream& operator>>(ostream& os, Patron& p)
{   
    return os << "\n\tUsername: " << p.getName() << endl
              << "\tUser ID: " << p.getID() << endl
              << "\tFee: " << p.get_fee() << endl;            
}