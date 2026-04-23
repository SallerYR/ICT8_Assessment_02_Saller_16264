#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int    isbn;
    bool   availability;
    string dateAdded;

public:
    // Default constructor
    Book();

    // Sets all details for the book at once
    void setBookDetails(string t, string a, int i, bool avail, string date);

    // Displays this book's details as one formatted row
    void displayBookDetails() const;

    // Borrows the book if available — returns true on success
    bool borrowBook();

    // Returns the book if borrowed — returns true on success
    bool returnBook();

    // Returns true if the book is available to borrow
    bool isAvailable() const;

    // Returns the ISBN so main() can search by it
    int getISBN() const;
};

#endif // BOOK_H