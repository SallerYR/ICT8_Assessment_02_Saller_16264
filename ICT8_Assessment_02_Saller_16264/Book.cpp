#include "Book.h"
#include <iomanip>  // setw, left
#include <iostream>
using namespace std;

// ── Default constructor
Book::Book()
{
    title = "";
    author = "";
    isbn = 0;
    availability = false;
    dateAdded = "";
}

// ── setBookDetails 
void Book::setBookDetails(string t, string a, int i, bool avail, string date)
{
    title = t;
    author = a;
    isbn = i;
    availability = avail;
    dateAdded = date;
}

// ── displayBookDetails 
// Prints one row aligned with the header printed in main().
void Book::displayBookDetails() const
{
    cout << left
        << setw(8) << isbn
        << setw(35) << title
        << setw(25) << author
        << setw(12) << (availability ? "Available" : "Borrowed")
        << setw(12) << dateAdded
        << endl;
}

// ── borrowBook 
// Returns true if the book was successfully borrowed, false if already borrowed.
bool Book::borrowBook()
{
    if (!availability)
    {
        return false;   // already borrowed – caller prints the error
    }
    availability = false;
    return true;
}

// ── returnBook 
// Returns true if the book was successfully returned, false if already on shelf.
bool Book::returnBook()
{
    if (availability)
    {
        return false;   // already on shelf – caller prints the error
    }
    availability = true;
    return true;
}

// ── isAvailable 
bool Book::isAvailable() const
{
    return availability;
}

// ── getISBN
int Book::getISBN() const
{
    return isbn;
}