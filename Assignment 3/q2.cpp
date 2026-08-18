#include <iostream>
using namespace std;
class tollBooth {
    private:
        unsigned int totalCars;
        double totalCash;
    public:
        tollBooth() : totalCars(0), totalCash(0.0) {}
        void payingCar() {
            totalCars++;
            totalCash+=0.50;
        }
        void nopayCar() {
            totalCars++;
        }
        void display() const {
            cout << "Total cars: " << totalCars << endl;
            cout << "Total cash: $" << totalCash << endl;
        }
};
int main() {
    tollBooth booth;
    char input;
    cout << "Press 'p' to count a paying car, 'n' to count a nonpaying car, 'e' to display totals and exit." << endl;
    bool running=true;
    while (running) {
        cin >> input;
        switch (input) {
            case 'p':
                booth.payingCar();
                cout << "Paying car recorded" << endl;
                break;
            case 'n':
                booth.nopayCar();
                cout << "Nonpaying car recorded" << endl;
                break;
            case 'e':
                booth.display();
                running = false;
                break;
            default:
                cout << "Invalid input!!" << endl;
        }
    }
    return 0;
}