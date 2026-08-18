#include <iostream>
#include <string>
using namespace std;
class FileSession {
    private:
        string fileName;
        int filePointerID;
        static int nextPointerID;
    public:
        FileSession(string name) : fileName(name) {
            filePointerID = ++nextPointerID;
            cout << "Constructor called, Opening file: " << fileName << " | Resource ID: " << filePointerID << endl;
        }
        ~FileSession() {
            cout << "Destructor called, Closing file: " << fileName << " | Releasing Resource ID: " << filePointerID << endl;
        }
};
int FileSession :: nextPointerID = 1000;
int main() {
    cout << "Stack Allocation:" << endl;
    {
        FileSession file1("a.txt");
        FileSession file2("b.txt");
        FileSession file3("c.txt");
        cout << "Destructors called automaticaly" << endl << endl;
    }
    cout << "Dynamic Allocation:" << endl;
    FileSession* df = new FileSession("temp.dat");
    cout << endl << "Dynamically allocated file:" << endl;
    cout << "Destructor is not called automatically. Manual deletion needed." << endl << endl;
    delete df;
    return 0;
}