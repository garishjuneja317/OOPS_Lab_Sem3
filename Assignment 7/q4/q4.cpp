#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: program source.txt destination.txt" << endl;
        return 1;
    }
    ifstream inFile(argv[1]);
    if (!inFile) {
        cout << "Error: Cannot open source file '" << argv[1] << "'" << endl;
        return 1;
    }
    ofstream outFile(argv[2]);
    if (!outFile) {
        cout << "Error: Cannot open destination file '" << argv[2] << "'" << endl;
        return 1;
    }
    char ch;
    int count = 0;
    while (inFile.get(ch)) {
        outFile.put(ch);
        count++;
    }
    inFile.close();
    outFile.close();
    cout << "File copied successfully." << endl;
    cout << "Number of characters copied: " << count << endl;
    return 0;
}