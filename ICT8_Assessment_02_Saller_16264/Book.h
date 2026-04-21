#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

// Book class represents one book in the library system
class Book
{
private:
    string title;
    string author;
    int    isbn;
    bool   availability;
    string dateAdded;

public:
    // Default constructor – initialises a blank/empty book
    Book();

    // Sets all details for the book at once
    void setBookDetails(string t, string a, int i, bool avail, string date);

    // Displays this book's details as one formatted row
    void displayBookDetails() const;

    // Borrows the book if it is currently available.
    // Returns true on success, false if the book is already borrowed.
    bool borrowBook();

    // Returns the book if it is currently borrowed.
    // Returns true on success, false if the book is already available.
    bool returnBook();

    // Returns true if the book is available to borrow
    bool isAvailable() const;

    // Returns the ISBN so main() can search by it
    int getISBN() const;
};

#endif // BOOK_H