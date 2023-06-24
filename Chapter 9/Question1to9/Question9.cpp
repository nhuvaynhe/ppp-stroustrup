/*  
    Question 9.
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
    Add 'Genre' for the Book class
    Create 'Patron' class for Library

    Creat 'Library' class

    Library class includes:
        vector of 'Book' and 'Patron'.

        struct 'Transaction'.
            Have it include a 'Book', a 'Patron' and a 'Date'.
        Make a vector 'Transaction'.

        add book to library.

        check out books.
            Make sure both user and book are in library.
                If they are not, report error.
            Make sure the user has no fees.
                If the user does, report error.
                If not, create a 'Transaction' and place it in vector 'Transaction'.

        return a vector that contain the name of user who owned fee.
*/

#include "std_lib_facilities.h"

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
string Book::Genre_to_String(Genre gen)
{
    switch (gen) {
        case Genre::Fiction:
            return "Fiction";
        case Genre::Nonfiction:
            return "Nonfiction";
        case Genre::Horror:
            return "Horror";
        case Genre::Thrill:
            return "Thrill";
        case Genre::Children:
            return "Children";
        default:
            return "Unknown Genre";
    }
}
//----------------------------------------------------------------------------------------------------
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

ostream& operator>>(ostream& os, Book& b)
{   
    Genre gen = b.getGenre();
    return os << "\n\tAuthour: " << b.getAuthour() << endl
              << "\tTitle: " << b.getTitle() << endl
              << "\tCopyright date: " << b.getDate() << endl
              << "\tGenre: " << b.Genre_to_String(gen) << endl
              << "\tISBN: " << b.getISBN() << endl;  
}
//----------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------

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
//----------------------------------------------------------------------------------------------------
ostream& operator>>(ostream& os, Patron& p)
{   
    return os << "\n\tUsername: " << p.getName() << endl
              << "\tUser ID: " << p.getID() << endl
              << "\tFee: " << p.get_fee() << endl;            
}
//----------------------------------------------------------------------------------------------------
class Library
{   
public:
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
//----------------------------------------------------------------------------------------------------
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

    string name = "Nguyen Ngoc Dai";
    int id = 2052933;
    Patron nhuvaynhe = Patron(name, id);

    string name2 = "Nguyen Yen Linh";
    int id2 = 2010341;
    Patron yenlinh = Patron(name2, id2);
    
    Library lb;
    lb.addBook(Jeffery);
    lb.addBook(Agatha);

    lb.addPatron(nhuvaynhe);
    lb.addPatron(yenlinh);

    lb.setPatronfee(nhuvaynhe);
    lb.Owned_user();

    lb.check_out(Jeffery, nhuvaynhe);

    cout >> Agatha;
}

