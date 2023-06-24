/*  
    Question 6.
    Chapter 9, page 339.
    07/04/2023
    Design and implement a 'Book' class.

    Book class must have:
        ISBN:  International Standard Book Number
            Form: n-n-n-x
                where 'n' is the integer and 'x' is digit or a letter
            Type: string
        Title
        Author
        Copyright date
        Checking a book in and out.

    Add operator for the Book class
*/

#include "std_lib_facilities.h"

//----------------------------------------------------------------------------------------------------
class Book {
public:
    Book(string author, string title, string copyright_date, string ISBN, bool Status)
        : bookAuthor{author}, bookTitle{title}, 
        bookDate{copyright_date}, bookISBN{ISBN}, checkoutStatus(Status) { }

    void print();
    bool ISBN_check();      // Check the format of ISBN
          
    void is_Check_out();    //Check the status of the book
    bool check_out();       // Check out the book
    
    string getISBN() { return bookISBN; }          
    string getAuthour() { return bookAuthor; }
    string getTitle() { return bookTitle; }
    string getDate() { return bookDate; }
private:
    string bookAuthor;
    string bookTitle;
    string bookDate;
    string bookISBN;

    bool checkoutStatus; 
};
//----------------------------------------------------------------------------------------------------
void Book::print() {
    cout << "\n\tAuthour: " << bookAuthor << endl
         << "\tTitle: " << bookTitle << endl
         << "\tCopyright date: " << bookDate << endl
         << "\tISBN: " << bookISBN << endl;  
}

bool Book::ISBN_check()
{   
    vector<int> position;       // save the position of '-' in ISBN
    for (int i=0; i < bookISBN.size(); ++i)
    {
        if (bookISBN[i] == '-') {
            position.push_back(i);
        }
    }  

    string set1;
    string set2;
    string set3;
    string set4;

    if (position.size() != 3){
        cout << "Wrong format!";
        return false;
    } else {
        set1 = bookISBN.substr(0, position[0]);
        // the second argument should be the length of 
        // the substring you want to extract, not the position of the next '-' character
        int length1 = position[1] - position[0] - 1;
        set2 = bookISBN.substr(position[0] +1, length1);

        int length2 = position[2] - position[1] - 1;
        set3 = bookISBN.substr(position[1] +1, length2);
            
        set4 = bookISBN.substr(position[2] +1);
    }

    string integer_set = set1 + set2 + set3;        // An only integer set n-n-n-x
    for (char c : integer_set){
        if (!(c >= '0' && '9' >= c)) return false;
    }

    for (char c : set4){                            // Check digit or character set
        if (!(isalpha(c) || isdigit(c))) return false;
    }

    return true;
}
//----------------------------------------------------------------------------------------------------
bool Book::check_out()       // Check if the user wanna borrow the book
{   
    string answer;
    cout << "You wanna borrow this book? [Y/N]" << endl;
    cin >> answer;
    if (answer == "Yes" || answer == "Y") {
        checkoutStatus = true;
        cout << "Book status: Checked out!" << endl;
    } else if (answer == "No" || answer == "N") {
        return checkoutStatus;
    } else { 
        cout << "Wrong input!"; 
    }

    return checkoutStatus;
}

void Book::is_Check_out()       //Check the book status
{
    if (checkoutStatus) {
        cout << "This book has been checked out!" << endl;
    } else {
        cout << "This book is available!" << endl;
    }
}
//----------------------------------------------------------------------------------------------------
bool operator==(Book b1, Book b2)
{   
    if (b1.getISBN() == b2.getISBN()) return true;
    else return false;
}

bool operator!=(Book b1, Book b2)
{
    return !(b1 == b2);
}

ostream& operator<<(ostream& os, Book& b)
{
    return os << "\n\tAuthour: " << b.getAuthour() << endl
              << "\tTitle: " << b.getTitle() << endl
              << "\tCopyright date: " << b.getDate() << endl
              << "\tISBN: " << b.getISBN() << endl;  
}
//----------------------------------------------------------------------------------------------------
int main()
{
    string tit = "The Bone Collector";
    string author = "Jeffery Deaver";
    string copyright_date = "06-03-1997";
    string isbn = "16-0-2002-Dai";
    bool status = false;
    Book Jeffery = Book(tit, author, copyright_date, isbn, status);

    string tit2 = "The ABC Murders";
    string author2 = "Agatha Christie";
    string copyright_date2 = "06-01-1936";
    string isbn2 = "16-0-2002-Dai";
    bool status2 = true;
    Book Agatha = Book(tit2, author2, copyright_date2, isbn2, status2);

    if (Jeffery == Agatha) cout << "Those two are the same!" << endl;
    else cout << "Not the same book!" << endl;

    cout <<Agatha;
    cout << Jeffery;
}   

