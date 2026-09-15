#include <iostream>
using namespace std;
class Shape {
    public:
        virtual double area() const = 0;
        virtual ~Shape() {};
};
class Rectangle : public Shape {
    private:
        double width;
        double height;
    public:
        Rectangle(double w, double h) {
            width=w;
            height=h;
        }
        double area() const {
            return width * height;
        }
};
class Circle : public Shape {
    private:
        double radius;
        const double PI = 3.14;
    public:
        Circle(double r) {
            radius=r;
        }
        double area() const {
            return PI * radius * radius;
        }
};
int main() {
    const int numShapes = 2;
    Shape* shapes[numShapes];
    shapes[0] = new Rectangle(5, 4);
    shapes[1] = new Circle(3);
    for (int i = 0; i < numShapes; ++i) {
        cout << "Area of Shape " << i+1 << ": " << shapes[i]->area() << endl;
    }
    for (int i = 0; i < numShapes; ++i) {
        delete shapes[i];
    }
    return 0;
}