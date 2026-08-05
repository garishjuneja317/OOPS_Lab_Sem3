#include <iostream>
using namespace std;
struct phone {
    int arCode;
    int ex;
    int num;
};
int main() {
    struct phone my;
    struct phone your;
    my.arCode=242;
    my.ex=767;
    my.num=8900;
    cout << "Enter the area code, exchange, and number: " << endl;
    cin >> your.arCode >> your.ex >> your.num;
    cout << "My number is (" << my.arCode << ") " << my.ex << "-" << my.num << endl;
    cout << "Your number is (" << your.arCode << ") " << your.ex << "-" << your.num << endl;
    return 0;
}