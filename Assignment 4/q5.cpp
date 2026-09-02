#include <iostream>
using namespace std;
class Date{
    private:
        int day;
        int month;
        int year;
        bool isLeap(int y) const {
            return (y%400==0)||(y%100!=0&&y%4==0);
        }
        int daysInMonth(int m,int y) const {
            if(m==2){
                if (isLeap(y)) {
                    return 29;
                }
                return 28;
            }
            if(m==4||m==6||m==9||m==11) {
                return 30;
            }
            return 31;
        }
        int toDays() const {
            int total=year*365;
            for(int y=1;y<year;y++){
                if(isLeap(y)) {
                    total++;
                }
            }
            for(int m=1;m<month;m++){
                total+=daysInMonth(m,year);
            }
            return total+day;
        }
    public:
        void input(){
            cout << "Enter day, month, year:" << endl;
            cin >> day >> month >> year;
        }
        Date operator++(){
            day++;
            if(day>daysInMonth(month,year)){
                day=1;
                month++;
                if(month>12){
                    month=1;
                    year++;
                }
            }
            return *this;
        }
        int operator-(const Date&other)const{
            int d1=this->toDays();
            int d2=other.toDays();
            if(d1>d2) {
                return d1-d2;
            }
            return d2-d1;
        }
        void display()const{
            cout << day << "/" << month << "/" << year << endl;
        }
};
int main(){
    Date d1;
    Date d2;
    d1.input();
    d2.input();
    int diff=d1-d2;
    cout << "Difference in days:" << diff << endl;
    cout << "Incrementing first date:" << endl;
    ++d1;
    d1.display();
    return 0;
}