#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the value of n:" << endl;
    cin >> n;
    int arr[n][n];
    cout << "Enter the elements:" << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    int rs=0, cs=0, re=n-1, ce=n-1;
    while ((rs <= re) && (cs <= ce)) {
        for (int i=rs; i<re; i++) {
            int temp = arr[rs][i];
            arr[rs][i] = arr[n-1-i][cs];
            arr[n-1-i][cs] = arr[re][n-1-i];
            arr[re][n-1-i] = arr[i][ce];
            arr[i][ce] = temp;
        }
        re--;
        ce--;
        rs++;
        cs++;
    }
    cout << "Array after rotating 90 degrees:" << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}