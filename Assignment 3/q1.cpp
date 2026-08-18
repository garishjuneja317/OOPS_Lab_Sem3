#include <iostream>
using namespace std;
class Obj {
    private:
        static int objCount;
        int serial;
    public:
        Obj() {
            objCount++;
            serial=objCount;
        }
        void sNo() const {
            cout << "Object number " << serial << endl;
        }
};
int Obj::objCount=0;
int main() {
    Obj obj1;
    Obj obj2;
    Obj obj3;
    obj1.sNo();
    obj2.sNo();
    obj3.sNo();
    return 0;
}