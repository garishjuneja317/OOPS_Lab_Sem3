#include <iostream>
#include <string>
using namespace std;
class BankAccount {
    private:
        string accNo;
        string holder;
        double balance;
        double rate;
    public:
        BankAccount(string accNo, string holder, double balance, double rate)
        : accNo(accNo), holder(holder), balance(balance), rate(rate) {}
        void deposit(double amount) {
            balance+=amount;
            cout << "Deposited the amount" << endl;
        }
        bool withdraw(double amount) {
            if (amount>balance) {
                cout << "Withdrawal not possible. Insufficient balance" << endl;
                return false;
            } else {
                balance-=amount;
                cout << "Withdrawal successful" << endl;
                return true;
            }
        }
        void calInt() {
            double interest = balance*rate/100;
            balance+=interest;
            cout << "Interest calculated and added in the balance." << endl;
        }
        void display() const {
            cout << "Account Number: " << accNo << " | Holder's Name: " << holder << " | Balance: " << balance << endl;
        }
        void transfer(BankAccount& target, double amount) {
            if (this->withdraw(amount)) {
                target.deposit(amount);
                cout << "Transfer successful." << endl;
            } else {
                cout << "Transfer failed." << endl;
            }
        }
};
int main() {
    BankAccount acc1("AC1", "Akhil Kumar", 1000, 3);
    BankAccount acc2("AC2", "Garish Juneja", 1200, 5);
    cout << "Initially:" << endl;
    acc1.display();
    acc2.display();
    cout << "Depositing 300 to AC1" << endl;
    acc1.deposit(300);
    cout << "Withdrawing 200 from AC2" << endl;
    acc2.withdraw(200);
    cout << "Adding interest to AC1 and AC2" << endl;
    acc1.calInt();
    acc2.calInt();
    cout << "Transfer 300 from AC1 to AC2" << endl;
    acc1.transfer(acc2, 300);
    cout << "Finally:" << endl;
    acc1.display();
    acc2.display();
    return 0;
}