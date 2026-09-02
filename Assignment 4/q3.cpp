#include <iostream>
#include <cmath>
using namespace std;
class Temperature {
    private:
        float celsius;
    public:
        Temperature operator+(const Temperature&other) const {
            Temperature sum;
            sum.celsius=this->celsius+other.celsius;
            return sum;
        }
        void input() {
            cout << "Enter temperature in Celsius:" << endl;
            cin >> celsius;
        }
        operator float() const {
            return (celsius*9.0/5.0)+32.0;
        }
        operator int() const {
            return round(celsius);
        }
        void display() const {
            cout << celsius << endl;
        }
};
int main() {
    Temperature t1;
    Temperature t2;
    t1.input();
    t2.input();
    Temperature sum=t1+t2;
    cout << "Sum in Celsius: ";
    sum.display();
    float fahrenheit=sum;
    cout << "Sum in Fahrenheit: " << fahrenheit << endl;
    int roundedCelsius=sum;
    cout << "Rounded Sum in Celsius: " << roundedCelsius << endl;
    return 0;
}