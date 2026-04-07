#include "Book.h"
#include <iomanip> // Including for setw and left manipulators - used in displayBookDetails 

// Assign values to all book attributes
void Book::setBookDetails(string t, string a, string i, bool av, string d)
{
    title = t;
    author = a;
    isbn = i;
    availability = av;
    dateAdded = d;
}

// Display one book's details
void Book::displayBookDetails()
{
    cout << left
        << setw(20) << title
        << setw(20) << author
        << setw(10) << isbn
        << setw(15) << (availability ? "Available" : "Borrowed")
        << setw(15) << dateAdded
        << endl;
}

// Borrow the book only if it is available
bool Book::borrowBook()
{
    if (availability)
    {
        availability = false;
        return true;
    }
    return false;
}

// Return the book and mark it as available
void Book::returnBook()
{
    availability = true;
}

// Return the ISBN of the book
string Book::getISBN()
{
    return isbn;
}

// Return the availability status
bool Book::isAvailable()
{
    return availability;
}
//    
// added comments to explain the code in Book.cpp file. 
// The Book class has private data members to store book details and public member functions to set details, display details, borrow and return books, and get the ISBN and availability status. 
// The displayBookDetails function uses manipulators to format the output in a tabular form.
