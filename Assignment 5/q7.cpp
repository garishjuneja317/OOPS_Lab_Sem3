#include <iostream>
using namespace std;
class Academic {
    protected:
        int marks;
    public:
        Academic(int m) {
            marks = m;
        }
};
class Sports {
    protected:
        int marks;
    public:
        Sports(int m) {
            marks = m;
        }
};
class Result : public Academic, public Sports {
    public:
        Result(int academicMarks, int sportsMarks) : Academic(academicMarks), Sports(sportsMarks) {}
        void displayTotal() {
            cout << "Academic Marks: " << Academic::marks << endl;
            cout << "Sports Marks: " << Sports::marks << endl;
            cout << "Total Score: " << Academic::marks + Sports::marks << endl;
        }
};
int main() {
    Result student(85, 90);
    cout << "Student Result:" << endl;
    student.displayTotal();
    return 0;
}