#include <iostream>
#include <string>
using namespace std;
class Book {
private:
    string title;
    string author;
    double price;
public:
    Book() {
        title = "Unknown";
        author = "Unknown";
        price = 0.0;
    }
    Book(string t, string a, double p) {
        title = t;
        author = a;
        price = p;
    }
    ~Book() {}
    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl << endl;
    }
};
int main() {
    int numBooks;
    cout << "Enter the number of books: ";
    cin >> numBooks;
    cin.ignore(); 
    Book* library = new Book[numBooks];
    for (int i = 0; i < numBooks; i++) {
        string t, a;
        double p;
        cout << "Enter details for Book " << i + 1 << ":" << endl;
        cout << "Title: ";
        getline(cin, t);
        cout << "Author: ";
        getline(cin, a);
        cout << "Price: ";
        cin >> p;
        cin.ignore(); 
        library[i] = Book(t, a, p);
    }
    cout << "\nLibrary Details:\n" << endl;
    for (int i = 0; i < numBooks; i++) {
        library[i].display();
    }
    delete[] library;
    return 0;
}