#include <iostream>
#include <string>
using namespace std;
class ElectricityBill {
    private:
        string name;
        double units;
        double bill;
    public:
        void input() {
            cout << "Enter name:" << endl;
            getline(cin, name);
            cout << "Enter units" << endl;
            cin >> units;
        }
        void calculate() {
            if (units<=300) {
                bill=units*8;
            } else if (units<=500) {
                bill=units*10;
            } else if (units<=800) {
                bill=units*12;
            } else {
                bill=units*15;
            }
        }
        void display() {
            cout << endl << "Electricity Bill:" << endl;
            cout << "Customer name: " << name << endl << "Units consumed: " << units << endl << "Total Bill Amount: " << bill << endl;
        }
};
int main() {
    ElectricityBill customer1;
    customer1.input();
    customer1.calculate();
    customer1.display();
    return 0;
}