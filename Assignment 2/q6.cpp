#include <iostream>
using namespace std;
int recSum(int* arr, int n) {
    if (n<=0) {
        return 0;
    }
    return *arr + recSum(arr+1, n-1);
}
int maxVal(int* arr, int n) {
    if (n==1) {
        return *arr;
    }
    int max = maxVal(arr+1, n-1);
    return (*arr > max ? *arr : max);
}
int main() {
    cout << "Enter the size of array: " << endl;
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements: " << endl;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int sum = recSum(arr, n);
    cout << "Sum = " << sum << endl;
    int max = maxVal(arr,n);
    cout << "Maximum Element = " << max << endl;
    return 0;
}