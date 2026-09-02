#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
    cout << "Enter the length of the arrays:" << endl;
    int n,m;
    cin >> n >> m;
    unordered_set<int> hash;
    int arr1[n], arr2[m], count=0;
    cout << "Enter elements of Array 1:" << endl;
    for (int i=0; i<n; i++) {
        cin >> arr1[i];
        hash.insert(arr1[i]);
    }
    cout << "Enter elements of Array 2:" << endl;
    for (int i=0; i<m; i++) {
        cin >> arr2[i];
        if (hash.contains(arr2[i])) {
            count++;
        }
    }
    int inter[count], u[n+m-count], j=0, k=0;
    for (int i=0; i<n; i++) {
        u[k]=arr1[i];
        k++;
    }
    for (int i=0; i<m; i++) {
        if (hash.contains(arr2[i])) {
            inter[j]=arr2[i];
            j++;
        } else {
            u[k]=arr2[i];
            k++;
        }
    }
    cout << "Union Array:" << endl;
    for (int i=0; i<n+m-count; i++) {
        cout << u[i] << " ";
    }
    cout << endl << "Intersection Array:" << endl;
    for (int i=0; i<count; i++) {
        cout << inter[i] << " ";
    }
}