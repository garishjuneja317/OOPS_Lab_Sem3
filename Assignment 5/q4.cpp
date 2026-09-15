#include <iostream>
#include <string>
using namespace std;
class Person {
    protected:
        string name;
        int age;
    public:
        Person(string n, int a) {
            name = n;
            age = a;
        }
        virtual void display() {
            cout << "Name: " << name << ", Age: " << age << endl;
        }
        virtual ~Person() {} 
};
class Student : public Person {
    private:
        int rollNo;
        double marks;
    public:
        Student(string n, int a, int r, double m) : Person(n, a) {
            rollNo = r;
            marks = m;
        }
        void display() {
            cout << "Student - Name: " << name << ", Age: " << age << ", Roll No: " << rollNo << ", Marks: " << marks << endl;
        }
};
class Teacher : public Person {
    private:
        string subject;
        double salary;
    public:
        Teacher(string n, int a, string sub, double sal) : Person(n, a) {
            subject = sub;
            salary = sal;
        }
        void display() {
            cout << "Teacher - Name: " << name << ", Age: " << age << ", Subject: " << subject << ", Salary: " << salary << endl;
        }
};

int main() {
    const int numPeople = 2;
    Person* people[numPeople];
    people[0] = new Student("Alice", 20, 101, 89.5);
    people[1] = new Teacher("Mr. Smith", 45, "Mathematics", 60000.0);
    for (int i = 0; i < numPeople; ++i) {
        people[i]->display();
    }
    return 0;
}