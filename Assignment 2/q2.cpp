#include <iostream>
using namespace std;
struct point {
    int x;
    int y;
};
int main() {
    struct point p1;
    struct point p2;
    struct point p3;
    cout << "Enter co-ordinates for p1: ";
    cin >> p1.x >> p1.y;
    cout << "Enter co-ordinates for p2: ";
    cin >> p2.x >> p2.y;
    p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;
    cout << "Co-ordinates of p1+p2 are: " << p3.x << ", " << p3.y;
    return 0;
}