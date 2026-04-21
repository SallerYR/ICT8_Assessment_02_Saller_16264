#include <iostream>
#include <iomanip>   // setw, left
#include <string>
#include "Book.h"
using namespace std;

// Constants
const int SIZE = 5;

// ── Helper: print table separator line
void printLine()
{
    cout << string(92, '-') << endl;
}

// ── Helper: print column header row 
void displayHeader()
{
    printLine();
    cout << left
        << setw(8) << "ISBN"
        << setw(35) << "TITLE"
        << setw(25) << "AUTHOR"
        << setw(12) << "STATUS"
        << setw(12) << "DATE ADDED"
        << endl;
    printLine();
}

// ── Helper: display all books
void displayAllBooks(Book books[], int size)
{
    displayHeader();
    for (int i = 0; i < size; i++)
    {
        books[i].displayBookDetails();
    }
    printLine();
}

// ── Helper: sort books array by ISBN (selection sort) 
void sortByISBN(Book books[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (books[j].getISBN() < books[minIdx].getISBN())
                minIdx = j;
        }
        if (minIdx != i)
        {
            Book temp = books[i];
            books[i] = books[minIdx];
            books[minIdx] = temp;
        }
    }
}

// ── Helper: find a book by ISBN, returns index or -1 
int findBookByISBN(Book books[], int size, int targetISBN)
{
    for (int i = 0; i < size; i++)
    {
        if (books[i].getISBN() == targetISBN)
            return i;
    }
    return -1;
}

// ── Helper: print the main menu
void displayMenu()
{
    cout << "\n==============================\n";
    cout << "   Library Book System Menu   \n";
    cout << "==============================\n";
    cout << "  1. Borrow Book\n";
    cout << "  2. Return Book\n";
    cout << "  3. Display Books\n";
    cout << "  4. Sort Books (by ISBN)\n";
    cout << "  0. Exit\n";
    cout << "==============================\n";
    cout << "Enter your choice: ";
}

// ── main ───────────────────────────────────────────────────────────────────────
int main()
{
    // Initialise exactly 5 books 
    Book books[SIZE];

    books[0].setBookDetails("C++ Primer", "Stanley B. Lippman", 1005, true, "2024-01-10");
    books[1].setBookDetails("Clean Code", "Robert C. Martin", 1002, true, "2024-02-15");
    books[2].setBookDetails("Python", "Mark Lutz", 1004, false, "2024-03-05");
    books[3].setBookDetails("The Pragmatic Programmer", "Andrew Hunt", 1001, true, "2024-01-25");
    books[4].setBookDetails("Introduction to Algorithms", "Thomas H. Cormen", 1003, true, "2024-04-01");

    // Sort by ISBN at startup
    sortByISBN(books, SIZE);

    int choice = -1;

    //  Main menu loop 
    while (true)
    {
        displayMenu();
        cin >> choice;

        // ── Option 0: Exit 
        if (choice == 0)
        {
            cout << "\nGoodbye!\n";
            break;
        }

        // ── Option 1: Borrow Book 
        else if (choice == 1)
        {
            cout << "\n-- Borrow Book --\n";
            displayAllBooks(books, SIZE);

            int userISBN;
            cout << "Enter ISBN to borrow (0 to cancel): ";
            cin >> userISBN;

            if (userISBN == 0)
            {
                cout << "Borrow cancelled.\n";
            }
            else
            {
                int index = findBookByISBN(books, SIZE, userISBN);

                if (index == -1)
                    cout << "Error: No book found with ISBN " << userISBN << ".\n";
                else if (books[index].borrowBook())
                    cout << "Success: Book borrowed successfully.\n";
                else
                    cout << "Error: That book is currently unavailable (already borrowed).\n";
            }
        }

        // ── Option 2: Return Book 
        else if (choice == 2)
        {
            cout << "\n-- Return Book --\n";
            displayAllBooks(books, SIZE);

            int userISBN;
            cout << "Enter ISBN to return (0 to cancel): ";
            cin >> userISBN;

            if (userISBN == 0)
            {
                cout << "Return cancelled.\n";
            }
            else
            {
                int index = findBookByISBN(books, SIZE, userISBN);

                if (index == -1)
                    cout << "Error: No book found with ISBN " << userISBN << ".\n";
                else if (books[index].returnBook())
                    cout << "Success: Book returned successfully.\n";
                else
                    cout << "Error: That book is already available in the library.\n";
            }
        }

        // ── Option 3: Display Books
        else if (choice == 3)
        {
            cout << "\n-- All Books --\n";
            displayAllBooks(books, SIZE);
        }

        // ── Option 4: Sort Books
        else if (choice == 4)
        {
            sortByISBN(books, SIZE);
            cout << "\n-- Books Sorted by ISBN --\n";
            displayAllBooks(books, SIZE);
        }

        // ── Invalid input 
        else
        {
            cout << "Invalid choice. Please enter 0-4.\n";
        }
    }

    return 0;
}
/*
    // Searches for the book by Index position inside array - otherwise returns -1 if not found
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
*/
