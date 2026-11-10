#include <iostream>
#include <string>
#include "student.h"
using namespace std;
void Student::input() {
    cout << "Enter Roll Number: ";
    cin >> rollNo;
    cout << "Enter Name: ";
    cin >> name;
}
void Student::display() {
    cout << "Roll Number: " << rollNo << endl;
    cout << "Name: " << name << endl;
}