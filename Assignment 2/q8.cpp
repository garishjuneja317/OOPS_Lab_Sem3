#include <iostream>
using namespace std;
int main() {
    cout << "Enter the size of array: " << endl;
    int n;
    cin >> n;
    int* arr = new int[n];
    cout << "Enter the elements: " << endl;
    for (int i=0; i<n; i++) {
        cin >> *(arr+i);
    }
    for (int i=0; i<n; i++) {
        cout << "Element value = " << *(arr+i) << ", Address = " << arr+i << endl;
    }
    return 0;
}
