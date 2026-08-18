#include <iostream>
#include <vector>
using namespace std;
class Matrix {
    private:
        vector<vector<int>> data;
        int rows;
        int cols;
    public:
        Matrix(int r, int c) : rows(r), cols(c) {
            data.resize(rows, vector<int>(cols, 0));
        }
        void input() {
            cout << "Enter the elements:" << endl;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    cin >> data[i][j];
                }
            }
        }
        void display() const {
            cout << "Transpose Matrix:" << endl;
            for (int i = 0; i < cols; ++i) {
                for (int j = 0; j < rows; ++j) {
                    cout << data[j][i] << " ";
                }
                cout << endl;
            }
        }
};
int main() {
    int r, c;
    cout << "Enter number of rows & columns:" << endl;
    cin >> r >> c;
    Matrix mat(r, c);
    mat.input();
    mat.display();
    return 0;
}