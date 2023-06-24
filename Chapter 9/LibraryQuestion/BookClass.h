/*
    Design and implement a 'Book' class.
*/


#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>

using namespace std;

//----------------------------------------------------------------------------------------------------
enum class Genre {
    Fiction=1, Nonfiction, Horror, Thrill, Children
};
//----------------------------------------------------------------------------------------------------
class Book {
public:
    Book(string author, string title, string copyright_date, string ISBN, Genre gen, bool Status)
        : bookAuthor{author}, bookTitle{title}, 
        bookDate{copyright_date}, bookISBN{ISBN}, bookGenre{gen}, checkoutStatus(Status) { }

    void print();
    bool ISBN_check();      // Check the format of ISBN
          
    void is_Check_out();    //Check the status of the book
    bool check_out();       // Check out the book
    
    string getISBN() { return bookISBN; }          
    string getAuthour() { return bookAuthor; }
    string getTitle() { return bookTitle; }
    string getDate() { return bookDate; }
    Genre getGenre() { return bookGenre; };

    string Genre_to_String(Genre gen);
private:
    string bookAuthor;
    string bookTitle;
    string bookDate;
    string bookISBN;
    Genre bookGenre;

    bool checkoutStatus; 
};
//----------------------------------------------------------------------------------------------------
bool operator==(Book b1, Book b2);
bool operator!=(Book b1, Book b2);
ostream& operator>>(ostream& os, Book& b);

#endif 