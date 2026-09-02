#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the value of n:" << endl;
    cin >> n;
    int arr[n-1];
    cout << "Enter the elements:" << endl;
    int sum=n*(n+1)/2, runningSum=0;
    for (int i=0; i<n-1; i++) {
        cin >> arr[i];
        runningSum=runningSum + arr[i];
    }
    cout << "The missing number is: " << sum-runningSum << endl;
}