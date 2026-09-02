#include <iostream>
#include <string>
using namespace std;
int main() {
    cout << "Enter the String:" << endl;
    string s;
    getline(cin, s);
    char* i=&s[0];
    char* j=&s[s.length()-1];
    while (*i<*j) {
        char temp = *i;
        *i = *j;
        *j = temp;
        i++;
        j--;
    }
    cout << "Reversed String: " << s << endl;
}