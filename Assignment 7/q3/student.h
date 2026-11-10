#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;
class Student {
private:
    int rollNo;
    string name;
public:
    void input();
    void display();
};
#endif