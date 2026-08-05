#include <iostream>
using namespace std;
int add(int a, int b) {
    return a+b;
}
int sub(int a, int b) {
    return a-b;
}
int m(int a, int b) {
    return a*b;
}
int d(int a, int b) {
    return a/b;
}
int main() {
    cout << "Enter two numbers: " << endl;
    int a,b;
    cin >> a >> b;
    cout << "Enter the opeartion: " << endl << "Enter + for addition, - for subtraction, * for multiplication, and / for division: " << endl;
    char ch;
    cin >> ch;
    int result;
    switch (ch) {
        case '+':
            result = add(a,b);
            break;
        case '-':
            result = sub(a,b);
            break;
        case '*':
            result = m(a,b);
            break;
        case '/':
            result = d(a,b);
            break;
        default:
            cout << "Invalid Input!" << endl;
            return 1;
    }
    cout << "Result = " << result << endl;
    return 0;
}
