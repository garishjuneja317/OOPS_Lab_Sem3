#include <iostream>
using namespace std;
class ComplexNumber {
    private:
        double real;
        double imag;
    public:
        ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
        ComplexNumber add(const ComplexNumber& other) const {
            return ComplexNumber(real + other.real, imag + other.imag);
        }
        ComplexNumber subtract(const ComplexNumber& other) const {
            return ComplexNumber(real - other.real, imag - other.imag);
        }
        void display() const {
            if (imag >= 0) {
                cout << real << " + " << imag << "i";
            } else {
                cout << real << " - " << -imag << "i";
            }
        }
        void input() {
            cin >> real >> imag;
        }
};
int main() {
    ComplexNumber c1;
    ComplexNumber c2;
    cout << "Enter the real and imaginary parts of the first number: " << endl;
    c1.input();
    cout << "Enter the real and imaginary parts of the second number: " << endl;
    c2.input();
    ComplexNumber sum = c1.add(c2);
    cout << "Result of Addition: ";
    sum.display();
    ComplexNumber difference = c1.subtract(c2);
    cout << endl << "Result of Subtraction: ";
    difference.display();
    cout << endl;
    return 0;
}