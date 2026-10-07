#include <iostream>
#include <string>
using namespace std;
class Student {
public:
    string name;
    int rollNo;
    int marks[5];
    double calculateAverage() {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            if (marks[i] < 0 || marks[i] > 100) {
                throw marks[i];
            }
            sum += marks[i];
        }
        return sum / 5.0;
    }
};
int main() {
    Student s;
    cout << "Enter name: ";
    getline(cin, s.name);
    cout << "Enter roll number: ";
    cin >> s.rollNo;
    cout << "Enter marks in 5 subjects: ";
    for (int i = 0; i < 5; i++) {
        cin >> s.marks[i];
    }
    try {
        double average = s.calculateAverage();
        cout << "Average marks: " << average << endl;
    }
    catch (int invalidMark) {
        cout << "Error: Invalid mark " << invalidMark
             << ". Marks must be between 0 and 100." << endl;
    }
    return 0;
}