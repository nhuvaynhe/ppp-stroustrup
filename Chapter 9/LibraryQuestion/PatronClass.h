/*
    Design and implement a 'Patron' class.
*/
#ifndef PATRON_H
#define PATRON_H


#include "BookClass.h"

class Patron
{
public:
    Patron(string name, int id, double fee) : username{name}, cardNumber{id}, libfee{fee} { }
    Patron(string name, int id) : username{name}, cardNumber{id}, libfee{0} { }

    void set_fee();
    double get_fee() { return libfee; }
    string getName() { return username; }
    int getID() { return cardNumber; }

private:
    string username;
    int cardNumber;
    double libfee;

    bool Owned;
};

ostream& operator>>(ostream& os, Patron& p);

#endif 