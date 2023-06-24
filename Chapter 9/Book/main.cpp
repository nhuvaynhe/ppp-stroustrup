/*
    Question 9.
    Chapter 9, page 339.
    10/04/2023
    Design and implement a 'Book' class.
    Design and implement a 'Patron' class.
    Design and implement a 'Library' class.
*/

#include "BookClass.h"

//----------------------------------------------------------------------------------------------------
int main()
{
    string tit = "The Bone Collector";
    string author = "Jeffery Deaver";
    string copyright_date = "06-03-1997";
    string isbn = "16-0-2002-Dai";
    bool status = false;
    Book Jeffery = Book(tit, author, copyright_date, isbn, Genre::Horror, status);

    string tit2 = "The ABC Murders";
    string author2 = "Agatha Christie";
    string copyright_date2 = "06-01-1936";
    string isbn2 = "16-0-2002-Dai";
    bool status2 = true;
    Book Agatha = Book(tit2, author2, copyright_date2, isbn2, Genre::Fiction, status2);
    
    cout >> Agatha;
}
