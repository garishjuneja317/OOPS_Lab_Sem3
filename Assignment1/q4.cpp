#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
    string s;
    ofstream f("file.txt");
    if (!f.is_open()) {
        cout << "Couldn't create the file." << endl;
        return 1;
    }
    cout << "Enter the strings:" << endl;
    getline(cin, s);
    while (s != "EXIT") {
        f << s << endl;
        getline(cin, s);
    }
    f.close();
    cout << "File created and written successfuly." << endl;
}