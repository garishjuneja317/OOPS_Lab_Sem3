#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ofstream outFile("numbers.txt");
    for (int i = 1; i <= 10; i++) {
        outFile << i << " ";
    }
    outFile.close();
    fstream file("numbers.txt", ios::in | ios::out);
    file.seekp(6, ios::beg);
    file << "99";
    file.seekg(0, ios::beg);
    int num;
    while (file >> num) {
        cout << num << " ";
    }
    cout << endl;
    file.close();
    return 0;
}