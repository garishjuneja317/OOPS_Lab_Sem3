#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ATM {
    private:
        string pin;
        double balance;
        vector<string> history;
        bool auth() const {
            string in;
            cout << "Enter the PIN for authentication:" << endl;
            cin >> in;
            if (in == pin) {
                return true;
            } else {
                cout << "Authentication failed." << endl;
                return false;
            }
        }
    public:
        ATM(string pin, double balance) : pin(pin), balance(balance) {
            history.push_back("Account created.");
        }
        void withdraw(double amount) {
            if (auth()) {
                if (amount <= balance) {
                    balance-=amount;
                    cout << "Withdrawal successful." << endl << endl;
                    history.push_back("Withdrew: " + to_string(amount));
                } else {
                    cout << "Not enough funds. Withdrawal Failed." << endl;
                }
            }
        }
        void deposit(double amount) {
            if (auth()) {
                balance+=amount;
                cout << "Deposit successful." << endl << endl;
                history.push_back("Deposited: " + to_string(amount));
            }
        }
        void chkBal() {
            if (auth()) {
                cout << endl<< "Balance: " << balance << endl;
            }
        }
        void miniStatement() {
            if (auth()) {
                cout << endl<< "Transaction History:" << endl;
                for (string s : history) {
                    cout << s << endl;
                }
                cout << endl << "Final Balance: " << balance << endl;
            }
        }
};
int main() {
    ATM atm("4261", 1000);
    atm.chkBal();
    double amount;
    cout << "Enter the amount to deposit:" << endl;
    cin >> amount;
    atm.deposit(amount);
    cout << "Enter the amount to withdraw:" << endl;
    cin >> amount;
    atm.withdraw(amount);
    cout << "Requesting mini statement:" << endl;
    atm.miniStatement();
    return 0;
}