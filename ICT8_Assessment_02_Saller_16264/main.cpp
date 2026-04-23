#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"
using namespace std;

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
void displayAllBooks(vector<Book>& books)
{
    displayHeader();
    for (int i = 0; i < (int)books.size(); i++)
    {
        books[i].displayBookDetails();
    }
    printLine();
}

// ── Helper: sort books by ISBN (selection sort)
void sortByISBN(vector<Book>& books)
{
    for (int i = 0; i < (int)books.size() - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < (int)books.size(); j++)
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
int findBookByISBN(vector<Book>& books, int targetISBN)
{
    for (int i = 0; i < (int)books.size(); i++)
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
    cout << "  5. Add Book\n";
    cout << "  0. Exit\n";
    cout << "==============================\n";
    cout << "Enter your choice: ";
}

// ── Helper: add a new book with full input validation
void addBook(vector<Book>& books)
{
    string title, author, dateAdded;
    int    isbn;
    char   availChar;
    bool   availability;

    cin.ignore(); // flush leftover newline from previous cin >> choice

    // ── Title: letters and spaces only
    while (true)
    {
        cout << "Enter title: ";
        getline(cin, title);
        bool valid = true;
        for (char c : title)
            if (!isalpha(c) && c != ' ') { valid = false; break; }
        if (valid && !title.empty()) break;
        cout << "Invalid: title must contain letters and spaces only.\n";
    }

    // ── Author: letters and spaces only
    while (true)
    {
        cout << "Enter author: ";
        getline(cin, author);
        bool valid = true;
        for (char c : author)
            if (!isalpha(c) && c != ' ') { valid = false; break; }
        if (valid && !author.empty()) break;
        cout << "Invalid: author must contain letters and spaces only.\n";
    }

    // ── ISBN: digits only, no duplicates
    while (true)
    {
        cout << "Enter ISBN (numbers only): ";
        string isbnStr;
        cin >> isbnStr;
        bool valid = true;
        for (char c : isbnStr)
            if (!isdigit(c)) { valid = false; break; }
        if (!valid)
        {
            cout << "Invalid: ISBN must be numbers only.\n";
            continue;
        }
        isbn = stoi(isbnStr);
        if (findBookByISBN(books, isbn) != -1)
        {
            cout << "Invalid: ISBN " << isbn << " already exists.\n";
            continue;
        }
        break;
    }

    // ── Availability: y or n only
    while (true)
    {
        cout << "Available? (y/n): ";
        cin >> availChar;
        if (availChar == 'y' || availChar == 'Y') { availability = true;  break; }
        if (availChar == 'n' || availChar == 'N') { availability = false; break; }
        cout << "Invalid: enter y or n.\n";
    }

    // ── Date Added
    cout << "Enter date added (DD-MM-YYYY): ";
    cin >> dateAdded;

    // ── Add to vector and keep sorted
    Book newBook;
    newBook.setBookDetails(title, author, isbn, availability, dateAdded);
    books.push_back(newBook);
    sortByISBN(books);
    cout << "Success: Book added.\n";
}

// ── main
int main()
{
    // Using vector instead of static array for dynamic resizing
    vector<Book> books;

    Book b;
    b.setBookDetails("C++ Primer", "Stanley B. Lippman", 1005, true, "10-01-2024");
    books.push_back(b);
    b.setBookDetails("Clean Code", "Robert C. Martin", 1002, true, "15-02-2024");
    books.push_back(b);
    b.setBookDetails("Python", "Mark Lutz", 1004, false, "05-03-2024");
    books.push_back(b);
    b.setBookDetails("The Pragmatic Programmer", "Andrew Hunt", 1001, true, "25-01-2024");
    books.push_back(b);
    b.setBookDetails("Introduction to Algorithms", "Thomas H. Cormen", 1003, true, "01-04-2024");
    books.push_back(b);

    // Sort by ISBN at startup
    sortByISBN(books);

    int choice = -1;

    // ── Main menu loop
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
            displayAllBooks(books);

            int userISBN;
            cout << "Enter ISBN to borrow (0 to cancel): ";
            cin >> userISBN;

            if (userISBN == 0)
            {
                cout << "Borrow cancelled.\n";
            }
            else
            {
                int index = findBookByISBN(books, userISBN);
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
            displayAllBooks(books);

            int userISBN;
            cout << "Enter ISBN to return (0 to cancel): ";
            cin >> userISBN;

            if (userISBN == 0)
            {
                cout << "Return cancelled.\n";
            }
            else
            {
                int index = findBookByISBN(books, userISBN);
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
            displayAllBooks(books);
        }

        // ── Option 4: Sort Books
        else if (choice == 4)
        {
            sortByISBN(books);
            cout << "\n-- Books Sorted by ISBN --\n";
            displayAllBooks(books);
        }

        // ── Option 5: Add Book
        else if (choice == 5)
        {
            cout << "\n-- Add Book --\n";
            addBook(books);
        }

        // ── Invalid input
        else
        {
            cout << "Invalid choice. Please enter 0-5.\n";
        }
    }

    return 0;
}