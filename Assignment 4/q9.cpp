#include <iostream>
using namespace std;
class Matrix {
    private:
        int rows;
        int cols;
        int data[10][10];
    public:
        void input() {
            cout << "Enter rows and cols:" << endl;
            cin >> rows >> cols;
            cout << "Enter elements:" << endl;
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    cin >> data[i][j];
                }
            }
        }
        int&operator()(int i,int j) {
            return data[i][j];
        }
        int operator()(int i,int j) const {
            return data[i][j];
        }
        void display() const {
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    cout << data[i][j] << " ";
                }
                cout << endl;
            }
        }
};
int main() {
    Matrix m;
    m.input();
    cout << "Original Matrix:" << endl;
    m.display();
    cout << "Element at (0,0): " << m(0,0) << endl;
    m(0,0)=99;
    cout << "Matrix after m(0,0)=99:" << endl;
    m.display();
    return 0;
}