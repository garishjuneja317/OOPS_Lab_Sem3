#include <iostream>
#include <string>
using namespace std;
int main() {
    cout << "Enter the sentence:" << endl;
    string s;
    getline(cin, s);
    int counter=0;
    int max=0;
    int first=0;
    string word;
    for (int i=0;i<s.length(); i++) {
        if (s[i]==' ') {
            counter=0;
            first=i+1;
            continue;
        }
        counter++;
        if (counter>max) {
            max=counter;
            word=s.substr(first, i+1-first);
        }
    }
    cout << "The word with maximum length is: " << word << endl;
}