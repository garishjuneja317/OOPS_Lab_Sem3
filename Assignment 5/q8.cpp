#include <iostream>
using namespace std;
class Base {
    protected:
        int protectedData;
};
class Derived : public Base {
    public:
        void modifyData(int value) {
            protectedData = value;
        }
        void displayData() {
            cout << "Protected Data Value: " << protectedData << endl;
        }
};
int main() {
    Derived obj;
    cout << "Accessing Protected Data via Derived Class..." << endl;
    obj.modifyData(100);
    obj.displayData();
    return 0;
}