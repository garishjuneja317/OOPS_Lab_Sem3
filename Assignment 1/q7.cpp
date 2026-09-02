#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    int arr1[26];
    int arr2[26];
    for (int i=0; i<26; i++) {
        arr1[i]=0;
        arr2[i]=0;
    }
    string s1,s2;
    cout << "Enter the string 1:" << endl;
    getline(cin, s1);
    cout << "Enter the string 2:" << endl;
    getline(cin, s2);
    for (int i=0; i<s1.length(); i++) {
        if (isupper(s1[i])) {
            tolower(s1[i]);
        }
        if (isupper(s2[i])) {
            tolower(s2[i]);
        }
        arr1[s1[i]-'a']++;
        arr2[s2[i]-'a']++;
    }
    bool mismatch = false;
    for (int i=0; i<26; i++) {
        if (arr1[i]!=arr2[i]) {
            mismatch=true;
            break;
        }
    }
    if (mismatch) {
        cout << "The strings are not anagrams." << endl;
    } else {
        cout << "The strings are anagrams." << endl;
    }
}