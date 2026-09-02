#include <iostream>
using namespace std;
class Fraction {
    private:
        int numerator;
        int denominator;
    public:
        void input() {
            cout << "Enter numerator and denominator:" << endl;
            cin >> numerator >> denominator;
        }
        Fraction operator/(const Fraction&other) const {
            Fraction temp;
            temp.numerator=this->numerator*other.denominator;
            temp.denominator=this->denominator*other.numerator;
            return temp;
        }
        operator double() const {
            return (double)numerator/denominator;
        }
        void display() const {
            cout << numerator << "/" << denominator << endl;
        }
};
int main() {
    Fraction f1;
    Fraction f2;
    f1.input();
    f2.input();
    Fraction div=f1/f2;
    cout << "Division result: ";
    div.display();
    double dec=div;
    cout << "Decimal equivalent: " << dec << endl;
    return 0;
}