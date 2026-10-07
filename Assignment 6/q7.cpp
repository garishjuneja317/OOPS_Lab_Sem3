#include <iostream>
#include <vector>
#include <string>
#include <exception>
using namespace std;
class InvalidItemException : public exception {
private:
    string message;
public:
    InvalidItemException(string msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};
class CreditLimitExceededException : public exception {
private:
    string message;
public:
    CreditLimitExceededException(double total, double limit) {
        message = "Total " + to_string(total) + " exceeds credit limit of " + to_string(limit);
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};
class Item {
public:
    string name;
    int quantity;
    double price;
    Item(string n, int q, double p) : name(n), quantity(q), price(p) {}
    double subtotal() const {
        return quantity * price;
    }
};
class ShoppingCart {
private:
    vector<Item> items;
    double creditLimit;
public:
    ShoppingCart(double limit) : creditLimit(limit) {}
    void addItem(Item item) {
        items.push_back(item);
    }
    void checkout() {
        double total = 0.0;
        for (const auto &item : items) {
            if (item.quantity < 0) {
                throw InvalidItemException("Invalid quantity for item: " + item.name);
            }
            if (item.price <= 0) {
                throw InvalidItemException("Invalid price for item: " + item.name);
            }
            total += item.subtotal();
        }
        if (total > creditLimit) {
            throw CreditLimitExceededException(total, creditLimit);
        }
        cout << "Checkout successful. Total amount: " << total << endl;
    }
};
int main() {
    ShoppingCart cart(500.0);
    cart.addItem(Item("Book", 2, 15.0));
    cart.addItem(Item("Pen", 5, 2.0));
    try {
        cart.checkout();
    }
    catch (InvalidItemException &e) {
        cout << "Invalid item error: " << e.what() << endl;
    }
    catch (CreditLimitExceededException &e) {
        cout << "Credit limit error: " << e.what() << endl;
    }
    ShoppingCart cart2(500.0);
    cart2.addItem(Item("Notebook", -1, 10.0));
    cart2.addItem(Item("Eraser", 2, 1.0));
    try {
        cart2.checkout();
    }
    catch (InvalidItemException &e) {
        cout << "Invalid item error: " << e.what() << endl;
    }
    catch (CreditLimitExceededException &e) {
        cout << "Credit limit error: " << e.what() << endl;
    }
    ShoppingCart cart3(500.0);
    cart3.addItem(Item("Pencil", 3, 0.0));
    try {
        cart3.checkout();
    }
    catch (InvalidItemException &e) {
        cout << "Invalid item error: " << e.what() << endl;
    }
    catch (CreditLimitExceededException &e) {
        cout << "Credit limit error: " << e.what() << endl;
    }
    ShoppingCart cart4(50.0);
    cart4.addItem(Item("Laptop", 1, 800.0));
    try {
        cart4.checkout();
    }
    catch (InvalidItemException &e) {
        cout << "Invalid item error: " << e.what() << endl;
    }
    catch (CreditLimitExceededException &e) {
        cout << "Credit limit error: " << e.what() << endl;
    }
    return 0;
}