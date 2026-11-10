#include <iostream>
#include "student.h"
using namespace std;
int main() {
    Student s;
    s.input();
    cout << "\nStudent Details:\n";
    s.display();
    return 0;
}

// Compile using the command "g++ main.cpp student.cpp -o program" after putting all the 3 files in a single folder.
// Run using the command ".\program"