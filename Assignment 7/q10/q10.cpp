#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    string filename = "test.txt";
    try {
        ifstream inFile;
        inFile.exceptions(ifstream::failbit | ifstream::badbit);
        inFile.open(filename);
        string line;
        getline(inFile, line);
        cout << "File content: " << line << endl;
        inFile.close();
        ofstream outFile;
        outFile.exceptions(ofstream::failbit | ofstream::badbit);
        outFile.open("output.txt");
        outFile << "Writing to file." << endl;
        outFile.close();
        cout << "Write successful." << endl;
    }
    catch (const ios_base::failure& e) {
        cout << "File Error caught: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "General Error caught: " << e.what() << endl;
    }
    return 0;
}