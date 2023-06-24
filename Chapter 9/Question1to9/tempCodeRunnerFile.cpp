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
