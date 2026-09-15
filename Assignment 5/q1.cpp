#include <iostream>
#include <string>
using namespace std;
class Employee {
    protected:
        string name;
        double salary;
    public:
        void inputEmployee() {
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter salary: ";
            cin >> salary;
        }
        void displayEmployee() {
            cout << "Name: " << name << endl;
            cout << "Salary: " << salary << endl;
        }
};
class Manager : public Employee {
    private:
        string department;
    public:
        void inputManager() {
            inputEmployee();
            cout << "Enter department: ";
            cin >> department;
        }
        void displayManager() {
            displayEmployee(); 
            cout << "Department: " << department << endl;
        }
};
int main() {
    Manager m;
    cout << "Input Data:" << endl;
    m.inputManager();
    cout << endl << "Output Data:" << endl;
    m.displayManager();
    return 0;
}