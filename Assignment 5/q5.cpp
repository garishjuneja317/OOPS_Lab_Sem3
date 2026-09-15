#include <iostream>
using namespace std;
class Account {
    protected:
        int accountNumber;
        double balance;
    public:
        Account(int accNum, double bal) {
            accountNumber = accNum;
            balance = bal;
        }
        virtual void withdraw(double amount) = 0;
        virtual void display() {
            cout << "Account: " << accountNumber << ", Balance: " << balance << endl;
        }
        virtual ~Account() {} 
};
class SavingsAccount : public Account {
    public:
        SavingsAccount(int accNum, double bal) : Account(accNum, bal) {}
        void withdraw(double amount) {
            if (balance - amount >= 500) {
                balance = balance - amount;
                cout << "Savings withdrawal of " << amount << " successful." << endl;
            } else {
                cout << "Savings withdrawal failed. Minimum balance of 500 required." << endl;
            }
        }
};
class CurrentAccount : public Account {
    public:
        CurrentAccount(int accNum, double bal) : Account(accNum, bal) {}
        void withdraw(double amount) {
            if (balance - amount >= -1000) {
                balance = balance - amount;
                cout << "Current withdrawal of " << amount << " successful." << endl;
            } else {
                cout << "Current withdrawal failed. Overdraft limit of -1000 reached." << endl;
            }
        }
};
int main() {
    const int numAccounts = 2;
    Account* accounts[numAccounts];
    accounts[0] = new SavingsAccount(1001, 2000.0);
    accounts[1] = new CurrentAccount(1002, 500.0);
    cout << "Initial Balances:" << endl;
    for(int i = 0; i < numAccounts; ++i) {
        accounts[i]->display();
    }
    cout << endl << "Attempting Withdrawals" << endl;
    accounts[0]->withdraw(1100.0); 
    accounts[1]->withdraw(1200.0); 
    cout << "Final Balances:" << endl;
    for(int i = 0; i < numAccounts; ++i) {
        accounts[i]->display();
    }
    return 0;
}