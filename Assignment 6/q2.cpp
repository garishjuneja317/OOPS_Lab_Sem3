#include <iostream>
#include <vector>
#include <string>
#include <exception>
using namespace std;
class BookNotAvailableException : public exception {
private:
    string message;
public:
    BookNotAvailableException(string title) {
        message = "Book not available: " + title + " is already issued.";
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};
class Book {
public:
    int id;
    string title;
    bool issued;

    Book(int i, string t) : id(i), title(t), issued(false) {}
};
class Library {
private:
    vector<Book> books;
public:
    void addBook(int id, string title) {
        books.push_back(Book(id, title));
    }
    void borrowBook(int id) {
        for (auto &b : books) {
            if (b.id == id) {
                if (b.issued) {
                    throw BookNotAvailableException(b.title);
                }
                b.issued = true;
                cout << "Book borrowed: " << b.title << endl;
                return;
            }
        }
        cout << "Book with id " << id << " not found." << endl;
    }
    void returnBook(int id) {
        for (auto &b : books) {
            if (b.id == id) {
                if (!b.issued) {
                    cout << "Book was not issued." << endl;
                } else {
                    b.issued = false;
                    cout << "Book returned: " << b.title << endl;
                }
                return;
            }
        }
        cout << "Book with id " << id << " not found." << endl;
    }
};
int main() {
    Library lib;
    lib.addBook(1, "C++ Primer");
    lib.addBook(2, "Effective C++");
    try {
        lib.borrowBook(1);
        lib.borrowBook(1);
    } catch (BookNotAvailableException &e) {
        cout << "Exception: " << e.what() << endl;
    }
    lib.returnBook(1);
    lib.borrowBook(1);
    return 0;
}