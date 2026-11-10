#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ofstream outFile("sample.txt");
    outFile << "This is the first line." << endl;
    outFile << "This is the second line." << endl;
    outFile << "This is the third line." << endl;
    outFile.close();
    ifstream inFile("sample.txt");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
    return 0;
}