#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;
int main() {
    ifstream f("file.txt");
    if (!f.is_open()) {
        cout << "Failed to open file." << endl;
        return 1;
    }
    char ch;
    int arr[26];
    for (int i=0; i<26; i++) {
        arr[i]=0;
    }
    while (f.get(ch)) {
        tolower(ch);
        arr[ch-'a']++;
    }
    f.close();
    cout << "The number of times each variable appears are: (a to z)" << endl;
    for (int i=0; i<26; i++) {
        cout << arr[i] << " ";
    }
}