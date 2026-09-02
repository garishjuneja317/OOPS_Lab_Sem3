#include <iostream>
using namespace std;
class Position {
    private:
        int x;
        int y;
    public:
        void input() {
            cout << "Enter x and y coordinates:" << endl;
            cin >> x >> y;
        }
        Position operator+(const Position&other) const {
            Position temp;
            temp.x=this->x+other.x;
            temp.y=this->y+other.y;
            return temp;
        }
        bool operator==(const Position&other) const {
            return (this->x==other.x)&&(this->y==other.y);
        }
        friend ostream&operator<<(ostream&os,const Position&pos) {
            os << "(" << pos.x << ", " << pos.y << ")";
            return os;
        }
};
int main() {
    Position p1;
    Position p2;
    p1.input();
    p2.input();
    Position p3=p1+p2;
    cout << "Position 1: " << p1 << endl;
    cout << "Position 2: " << p2 << endl;
    cout << "After addition: " << p3 << endl;
    if (p1==p2) {
        cout << "Positions are equal." << endl;
    } else {
        cout << "Positions are not equal." << endl;
    }
    return 0;
}