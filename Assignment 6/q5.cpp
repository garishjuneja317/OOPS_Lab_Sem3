#include <iostream>
#include <string>
#include <exception>
using namespace std;
class AccountLockedException : public exception {
private:
    string message;
public:
    AccountLockedException(string msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};
class InsufficientFundsException : public exception {
private:
    string message;
public:
    InsufficientFundsException(string msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};
class ATM {
private:
    double balance;
    int pin;
    int wrongAttempts;
    bool locked;
    bool verifyPIN(int enteredPin) {
        if (locked) {
            throw AccountLockedException("Account is locked. Please contact bank.");
        }
        if (enteredPin != pin) {
            wrongAttempts++;
            if (wrongAttempts > 3) {
                locked = true;
                throw AccountLockedException("Too many wrong PIN attempts. Account locked.");
            }
            return false;
        }
        wrongAttempts = 0;
        return true;
    }
public:
    ATM(double initialBalance, int initialPin)
        : balance(initialBalance), pin(initialPin), wrongAttempts(0), locked(false) {}
    void checkBalance(int enteredPin) {
        if (!verifyPIN(enteredPin)) {
            cout << "Invalid PIN." << endl;
            return;
        }
        cout << "Current balance: " << balance << endl;
    }
    void deposit(int enteredPin, double amount) {
        if (!verifyPIN(enteredPin)) {
            cout << "Invalid PIN." << endl;
            return;
        }
        if (amount <= 0) {
            cout << "Invalid deposit amount." << endl;
            return;
        }
        balance += amount;
        cout << "Deposited: " << amount << ". New balance: " << balance << endl;
    }
    void withdraw(int enteredPin, double amount) {
        if (!verifyPIN(enteredPin)) {
            cout << "Invalid PIN." << endl;
            return;
        }
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
            return;
        }
        if (amount > balance) {
            throw InsufficientFundsException("Insufficient funds. Available balance: " + to_string(balance));
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << ". New balance: " << balance << endl;
    }
};
int main() {
    ATM atm(1000.0, 1234);
    int choice;
    while (true) {
        cout << "\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 4) {
            break;
        }
        int enteredPin;
        cout << "Enter PIN: ";
        cin >> enteredPin;
        try {
            if (choice == 1) {
                atm.checkBalance(enteredPin);
            } else if (choice == 2) {
                double amount;
                cout << "Enter deposit amount: ";
                cin >> amount;
                atm.deposit(enteredPin, amount);
            } else if (choice == 3) {
                double amount;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                atm.withdraw(enteredPin, amount);
            } else {
                cout << "Invalid choice." << endl;
            }
        }
        catch (AccountLockedException &e) {
            cout << "Exception: " << e.what() << endl;
            break;
        }
        catch (InsufficientFundsException &e) {
            cout << "Exception: " << e.what() << endl;
        }
    }
    return 0;
}