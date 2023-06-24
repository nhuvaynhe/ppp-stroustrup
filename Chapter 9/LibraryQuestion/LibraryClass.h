/*
    Design and implement a 'Library' class.
*/

#ifndef LIBRARY_H
#define LIBRARY_H

#include "PatronClass.h"

//----------------------------------------------------------------------------------------------------
class Library
{   
public:
    Library();
    
    struct Transaction {
        Book bookName;
        Patron patronName;
        Transaction(Book n, Patron p) : bookName{n}, patronName{p} { }
    };

    vector<Book> Bookset;
    vector<Patron> Patronset;
    vector<Transaction> TransactionHistory;

    bool isBookInLibrary(Book& b);
    bool isUserInLibrary(Patron& p);
    

    void addBook(Book& b) { Bookset.push_back(b); }
    void addPatron(Patron& p) { Patronset.push_back(p); }
    void check_out(Book& b, Patron& p);
    void Owned_user();
    void setPatronfee(Patron& p);

    void print();
};

#endif //LIBRARY_H