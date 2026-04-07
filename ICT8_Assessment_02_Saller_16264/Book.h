#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

// Book class represents one book in the library
class Book
{
private:
    // Private data members (encapsulation)
    string title;
    string author;
    string isbn;
    bool availability;
    string dateAdded;

public:
    // Sets all details of the book
    void setBookDetails(string t, string a, string i, bool av, string d);

    // Displays book details in formatted output
    void displayBookDetails();

    // Borrows the book if available
    // Returns true if borrowing is successful, false otherwise
    bool borrowBook();

    // Returns the book and marks it as available
    void returnBook();

    // Returns the ISBN of the book
    string getISBN();

    // Returns true if the book is available
    bool isAvailable();
};

#endif
//test
