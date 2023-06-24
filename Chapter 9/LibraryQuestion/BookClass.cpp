/*
    Question 9.
    Chapter 9, page 339.
    07/04/2023
    Design and implement a 'Book' class.
*/

#include "BookClass.h"

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
//----------------------------------------------------------------------------------------------------
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