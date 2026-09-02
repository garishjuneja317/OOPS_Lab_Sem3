#include <iostream>
using namespace std;
class Currency {
    private:
        int rupees;
        int paise;
    public:
        Currency operator+(const Currency& other) const {
            int total = this->toTotalPaise()+other.toTotalPaise();
            Currency sum;
            sum.rupees=total/100;
            sum.paise=total%100;
            return sum;
        }
        Currency operator-(const Currency& other) const {
            int total = this->toTotalPaise()-other.toTotalPaise();
            Currency diff;
            diff.rupees=total/100;
            diff.paise=total%100;
            return diff;
        }
        Currency operator*(const Currency& other) const {
            int total = this->toTotalPaise()*other.toTotalPaise();
            total = total / 100; 
            Currency mul;
            mul.rupees=total/100;
            mul.paise=total%100;
            return mul;
        }
        bool operator==(const Currency& other) const {
            return this->toTotalPaise() == other.toTotalPaise();
        }
        int toTotalPaise() const {
            return (rupees*100)+paise;
        }
        void input() {
            cout << "Enter the amount in rupees and paise:" << endl;
            cin >> rupees >> paise;
        }
        void display() const {
            cout << "Rs. " << rupees << "." << (paise<10?"0":"") << paise << endl;
        }
};
int main() {
    Currency c1;
    Currency c2;
    c1.input();
    c2.input();
    Currency sum = c1+c2;
    Currency diff = c1-c2;
    Currency prod = c1*c2;
    cout << "Addition: ";
    sum.display();
    cout << "Subtraction: ";
    diff.display();
    cout << "Multiplication: ";
    prod.display();
    if (c1==c2) {
        cout << "Currency 1 is equal to Currency 2." << endl;
    } else {
        cout << "Currency 1 is not equal to Currency 2." << endl;
    }
    return 0;
}