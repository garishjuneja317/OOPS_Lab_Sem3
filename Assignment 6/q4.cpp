#include <iostream>
#include <vector>
#include <exception>
#include <string>
using namespace std;
class MatrixDimensionException : public exception {
private:
    string message;
public:
    MatrixDimensionException(string msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};
typedef vector<vector<int>> Matrix;
Matrix inputMatrix(string name) {
    int rows, cols;
    cout << "Enter rows and columns for matrix " << name << ": ";
    cin >> rows >> cols;
    Matrix mat(rows, vector<int>(cols));
    cout << "Enter elements of matrix " << name << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }
    return mat;
}
void printMatrix(const Matrix &mat) {
    for (const auto &row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
Matrix addMatrices(const Matrix &A, const Matrix &B) {
    if (A.size() != B.size() || A[0].size() != B[0].size()) {
        throw MatrixDimensionException("Matrices must have the same dimensions for addition.");
    }
    int rows = A.size();
    int cols = A[0].size();
    Matrix C(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}
Matrix multiplyMatrices(const Matrix &A, const Matrix &B) {
    if (A[0].size() != B.size()) {
        throw MatrixDimensionException("Number of columns of first matrix must equal number of rows of second matrix for multiplication.");
    }
    int rows = A.size();
    int cols = B[0].size();
    int common = A[0].size();
    Matrix C(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < common; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
int main() {
    Matrix A = inputMatrix("A");
    Matrix B = inputMatrix("B");
    int choice;
    cout << "Choose operation:\n1. Addition\n2. Multiplication\nEnter choice: ";
    cin >> choice;
    try {
        Matrix C;
        if (choice == 1) {
            C = addMatrices(A, B);
            cout << "Result of addition:\n";
        } else if (choice == 2) {
            C = multiplyMatrices(A, B);
            cout << "Result of multiplication:\n";
        } else {
            cout << "Invalid choice." << endl;
            return 0;
        }
        printMatrix(C);
    }
    catch (MatrixDimensionException &e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}