#include <iostream>
#include <string> // For string data type 
#include "Book.h"
#include <iomanip> // Manipulators for formatting output
using namespace std;

// Function to display a line separator
void printLine()
{
    cout << "-------------------------------------------------------------------------------" << endl;



}

// Function to display heading for book table aligned with book details
void displayHeader()
{
    printLine();
    cout << left
        << setw(20) << "TITLE"
        << setw(20) << "AUTHOR"
        << setw(10) << "ISBN"
        << setw(15) << "STATUS"
        << setw(15) << "DATE ADDED"
        << endl;
    printLine();
}

// Function to display all books in the array
void displayAllBooks(Book books[], int size)
{
    displayHeader();

    for (int i = 0; i < size; i++)
    {
        books[i].displayBookDetails();
    }

    printLine();
}

// Function to sort books by ISBN using Insertion Sort
void sortBooksByISBN(Book books[], int size)
{
    for (int i = 1; i < size; i++)
    {
        Book keyBook = books[i];
        int j = i - 1;

        // Move books with larger ISBN values one position ahead
        while (j >= 0 && books[j].getISBN() > keyBook.getISBN())
        {
            books[j + 1] = books[j];
            j--;
        }

        books[j + 1] = keyBook;
    }
}

// Function to search for a book by ISBN
// Returns the index if found, otherwise returns -1
int findBookByISBN(Book books[], int size, string isbn)
{
    for (int i = 0; i < size; i++)
    {
        if (books[i].getISBN() == isbn)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    const int SIZE = 5;

    // Create array of 5 Book objects
    Book books[SIZE];

    // Initialize sample data
    books[0].setBookDetails("C++ Primer", "Stanley B. Lippman", "1005", true, "2024-01-10");
    books[1].setBookDetails("OOP Guide", "Rudolf Pecinovsky", "1002", true, "2024-02-15");
    books[2].setBookDetails("Python", "Mark Lutz", "1004", false, "2024-03-05");
    books[3].setBookDetails("JavaScript", "David Flanagan", "1001", true, "2024-01-25");
    books[4].setBookDetails("HTML & CSS", "Jon Duckett", "1003", true, "2024-04-01");

    // Display unsorted books
    cout << "\nLIBRARY BOOK LIST (BEFORE SORTING)\n";
    displayAllBooks(books, SIZE);

    // Sort books by ISBN using Insertion Sort
    sortBooksByISBN(books, SIZE);

    // Display sorted books
    cout << "\nLIBRARY BOOK LIST (AFTER SORTING BY ISBN)\n";
    displayAllBooks(books, SIZE);

    string userISBN;

    // Repeat until user enters 0
    while (true)
    {
        cout << "\nEnter ISBN to borrow a book (or 0 to exit): ";
        cin >> userISBN;

        // Exit condition
        if (userISBN == "0")
        {
            cout << "\nProgram terminated. Thank you.\n";
            break;
        }

        // Simple input validation
        if (userISBN == "")
        {
            cout << "Invalid input. Please enter a valid ISBN.\n";
            continue;
        }

        // Search for the book
        int index = findBookByISBN(books, SIZE, userISBN);

        if (index == -1)
        {
            cout << "Error: ISBN not found.\n";
        }
        else
        {
            if (books[index].borrowBook())
            {
                cout << "Book borrowed successfully.\n";
            }
            else
            {
                cout << "Book is unavailable.\n";
            }
        }

        // Show updated list after each attempt
        cout << "\nUPDATED BOOK LIST\n";
        displayAllBooks(books, SIZE);
    }

    return 0;
}

//
//
// adding to commit - test