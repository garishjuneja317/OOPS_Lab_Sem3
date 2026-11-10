#include <iostream>
using namespace std;
class Date {
private:
    int day;
    int month;
    int year;
public:
    void setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    void increment() {
        int daysInMonth;
        if (month == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            daysInMonth = 30;
        } else {
            daysInMonth = 31;
        }
        day++;
        if (day > daysInMonth) {
            day = 1;
            month++;

            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
    void display() {
        cout << day << "/" << month << "/" << year << endl;
    }
};
int main() {
    Date d;
    int d_input, m_input, y_input;
    cout << "Enter day, month, and year: ";
    cin >> d_input >> m_input >> y_input;
    d.setDate(d_input, m_input, y_input);
    cout << "Current Date: ";
    d.display();
    d.increment();
    cout << "After incrementing by one day: ";
    d.display();
    return 0;
}