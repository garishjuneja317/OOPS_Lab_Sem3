#include <iostream>
#include <string>
using namespace std;
class Vehicle {
    protected:
        string make;
        string model;
    public:
        Vehicle(string m, string mod) {
            make = m;
            model = mod;
        }
        virtual void display() {
            cout << "Make: " << make << ", Model: " << model << endl;
        }
        virtual ~Vehicle() {} 
};
class Car : public Vehicle {
    private:
        int numDoors;
    public:
        Car(string m, string mod, int doors) : Vehicle(m, mod) {
            numDoors = doors;
        }
        void display() {
            cout << "Car - Make: " << make << ", Model: " << model << ", Doors: " << numDoors << endl;
        }
};
class Bike : public Vehicle {
    private:
        bool hasGear;
    public:
        Bike(string m, string mod, bool gear) : Vehicle(m, mod) {
            hasGear = gear;
        }
        void display() {
            cout << "Bike - Make: " << make << ", Model: " << model << ", Has Gear: ";
            if (hasGear == true) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
};
int main() {
    const int numVehicles = 2;
    Vehicle* vehicles[numVehicles];
    vehicles[0] = new Car("Honda", "Civic", 4);
    vehicles[1] = new Bike("Yamaha", "R1", true);
    for (int i = 0; i < numVehicles; ++i) {
        vehicles[i]->display();
    }
    for (int i = 0; i < numVehicles; ++i) {
        delete vehicles[i];
    }
    return 0;
}