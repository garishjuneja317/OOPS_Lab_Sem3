#include <iostream>
using namespace std;
class Employee {
    protected:
        int employeeId;
    public:
        Employee(int id) {
            employeeId = id;
        }
        void displayEmployee() {
            cout << "Employee ID: " << employeeId << endl;
        }
};
class Engineer : virtual public Employee {
    public:
        Engineer(int id) : Employee(id) {}
        void displayEngineer() {
            cout << "Role: Engineer" << endl;
        }
};
class Manager : virtual public Employee {
    public:
        Manager(int id) : Employee(id) {
        }
        void displayManager() {
            cout << "Role: Manager" << endl;
        }
};
class SoftwareEngineer : public Engineer, public Manager {
    public:
        SoftwareEngineer(int id) : Employee(id), Engineer(id), Manager(id) {}
        void displayDetails() {
            displayEmployee();
            displayEngineer();
            displayManager();
            cout << "Specialization: Software Engineer" << endl;
        }
};
int main() {
    SoftwareEngineer se(90125);
    cout << "Software Engineer Data:" << endl;
    se.displayDetails();
    return 0;
}