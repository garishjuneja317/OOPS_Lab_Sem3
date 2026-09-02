#include <iostream>
#include <cmath>
using namespace std;
class Polar {
    private:
        double radius;
        double angle;
    public:
        Polar operator+(const Polar& other) {
            double x1=radius*cos(angle);
            double y1=radius*sin(angle);
            double x2=other.radius*cos(other.angle);
            double y2=other.radius*sin(other.angle);
            double sumX=x1+x2;
            double sumY=y1+y2;
            Polar answer;
            answer.radius=sqrt(sumX*sumX + sumY*sumY);
            answer.angle=atan2(sumY, sumX);
            return answer;
        }
        void input() {
            cout << "Enter radius and angle for the point:" << endl;
            cin >> radius >> angle;
        }
        void display() const {
            cout << "(" << radius << ", " << angle << ")" << endl;
        }
};
int main() {
    Polar point1;
    Polar point2;
    point1.input();
    point2.input();
    Polar result=point1+point2;
    cout << "Sum: ";
    result.display();
    return 0;
}