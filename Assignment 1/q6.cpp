#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter number of total stairs:" << endl;
    cin >> n;
    cout << "Number of Ways = ";
    int x=1, y=2;
    if (n==1) {
        cout << x;
    } else if (n==2) {
        cout << y;
    } else {
        for (int i=3;i<=n;i++) {
            y=x+y;
            x=y-x;
        }
        cout << y;
    }
}