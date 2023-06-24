/*
    Question 9.
    Chapter 9, page 339.
    10/04/2023
    Design and implement a 'Book' class.
    Design and implement a 'Patron' class.
    Design and implement a 'Library' class.
*/

#include "LibraryClass.h"
//----------------------------------------------------------------------------------------------------
Library::Library(){}

bool Library::isBookInLibrary(Book& b)
{
    for (Book name : Bookset){
        if (b.getISBN() == name.getISBN()) return true;
    }

    return false;
}

bool Library::isUserInLibrary(Patron& p)
{
    for (Patron name : Patronset){
        if (p.getName() == name.getName()) return true;
    }

    return false;
}
//----------------------------------------------------------------------------------------------------
void Library::check_out(Book& b, Patron& p)
{  
    double checkfee;
    if (!(isBookInLibrary(b))) {
        cout << "Book is not available in library!" <<endl;
    } else if (!(isUserInLibrary(p))) {
        cout << "Username has not created" <<endl;
    } else {
        for (int i=0; i<Patronset.size(); ++i) {
            if (p.getName() == Patronset[i].getName()) 
            {
                checkfee = Patronset[i].get_fee();
            }
        }
    }

    if (checkfee > 0) {
        cout << "Pay the fee before borrowing our book!";
    } else {
        TransactionHistory.push_back(Transaction(b, p));
        cout << "Your transaction is finished, you can get your book!" << endl;
    }
}
//----------------------------------------------------------------------------------------------------
void Library::setPatronfee(Patron& p)
{
    if (!(isUserInLibrary(p))) {
        cout << "Username has not created" <<endl;
    } else {
        for (int i=0; i<Patronset.size(); ++i) {
            if (p.getName() == Patronset[i].getName()) {
                Patronset[i].set_fee();
            }
        }
    }
}

void Library::Owned_user()
{   
    cout << "\nThe user who owned is: " << endl;
    for (Patron p : Patronset)
    {
        if (p.get_fee() > 0) {
            cout << '\t' << p.getName() << endl;
        }
    }
}
//----------------------------------------------------------------------------------------------------
void Library::print()
{
    for (Book b : Bookset)
    {
        cout >> b;
    }

    for (Patron p : Patronset)
    {
        cout >> p;
    }
}