#include <iostream>
using namespace std;
void swap(int*& a, int*& b) {
    int* temp = a;
    a=b;
    b=temp;
}
int main() {
    int x,y;
    cout << "Enter two numbers to swap: ";
    cin >> x >> y;
    int* a = &x;
    int* b = &y;
    cout << "Before swapping: " << *a << " " << *b << endl;
    swap(a, b);
    cout << "After swapping: " << *a << " " << *b;
    return 0;
}