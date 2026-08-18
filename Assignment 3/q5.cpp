#include <iostream>
using namespace std;
class angle {
    private:
        int deg;
        float min;
        char dir;
    public:
        angle(int d = 0, float m = 0.0f, char dir = 'N') : deg(d), min(m), dir(dir) {}
        void getAngle() {
            cout << "Enter degrees: ";
            cin >> deg;
            cout << "Enter minutes: ";
            cin >> min;
            cout << "Enter direction (N, S, E, or W): ";
            cin >> dir;
        }
        void displayAngle() const {
            cout << deg << '\xF8' << min << "' " << dir;
        }
};
int main() {
    char i;
    angle customAngle;
    do {
        customAngle.getAngle();
        cout << "Angle: ";
        customAngle.displayAngle();
        cout << endl;
        cout << "Enter 'y' to continue, and 'n' to stop: ";
        cin >> i;
    } while (i == 'y');
    return 0;
}