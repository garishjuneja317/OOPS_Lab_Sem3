#include <iostream>
#include <string>
using namespace std;
class TempStorage {
    private:
        string name;
    public:
        TempStorage(string name) : name(name) {
            cout << "Contructor called, creating temporary file: " << name << endl;
        }
        ~TempStorage() {
            cout << "Destructor called, deleting temporary file: " << name << endl;
        }
};
void function() {
    cout << "Function: " << endl;
    TempStorage temp1("a.txt");
    TempStorage temp2("b.txt");
    cout << "Exiting function, destructors called automatically." << endl;
}
int main() {
    function();
    cout << endl << "Dynamic Allocation:" << endl;
    TempStorage* df = new TempStorage("df.txt");
    cout << "Created dynamic temporary file, now destrutor needs to be called manually." << endl;
    delete df;
    return 0;
}