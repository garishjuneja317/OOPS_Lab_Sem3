#include <iostream>
#include <cstring>
using namespace std;
void sort(const char* arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                const char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    const char* arr[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Original Array:" << endl;
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    sort(arr, n);
    cout << "Alphabetically sorted array:" << endl;
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}