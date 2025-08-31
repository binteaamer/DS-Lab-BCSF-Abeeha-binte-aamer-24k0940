/*Write a C++ program that dynamically creates a 2D matrix and provides:
=> Addition of two matrices.
=> Subtraction of two matrices.
=> Ensure safe memory handling with proper allocation/deallocation.*/

//code
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter cols: ";
    cin >> cols;

    int** matrix1 = new int*[rows];
    int** matrix2 = new int*[rows];
    int** add = new int*[rows];
    int** sub = new int*[rows];

    for (int i = 0; i < rows; i++) {
        matrix1[i] = new int[cols];
        matrix2[i] = new int[cols];
        add[i] = new int[cols];
        sub[i] = new int[cols];
    }

    cout << "Enter elements of matrix1:" << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix1[i][j];

    cout << "Enter elements of matrix2:" << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix2[i][j];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            add[i][j] = matrix1[i][j] + matrix2[i][j];
            sub[i][j] = matrix1[i][j] - matrix2[i][j];
        }

    cout << "Addition of matrices:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << add[i][j] << " ";
        cout << endl;
    }

    cout << "Subtraction of matrices:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << sub[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] add[i];
        delete[] sub[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] add;
    delete[] sub;

    return 0;
}
