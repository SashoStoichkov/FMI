#include <iostream>
#include <cstring>
using namespace std;

int **enterMatrix(int rows, int cols) {
    int **matrix = new int*[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];

        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

void deleteMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void printMatrix(int **matrix, int rows, int cols) {
    cout << endl << "Matrix is:" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

void zad1() {
    int size;
    cout << "Enter size: ";
    cin >> size;

    int **matrix = new int*[size];

    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];

        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }

    int counter = size;
    cout << endl << "Result: " << endl;

    for (int i = 0; i < size; i++) {
        // for (int j = 0; j < size; j++) {
        //     if (size - 1 - j >= i) {
        //         cout << matrix[i][j] << " ";
        //     }
        // }
        // cout << endl;

        for (int j = 0; j < counter; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;

        counter -= 1;
    }

    deleteMatrix(matrix, size);
}

int solution3(int **matrix, int rows, int cols) {
    int result = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (cols - 1 - j < i) {
                int number = matrix[i][j];
                // cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }

    return result;
}

void zad3() {
    int rows;
    cout << "Enter rows: "; cin >> rows;

    int cols;
    cout << "Enter cols: "; cin >> cols;

    int **matrix = enterMatrix(rows, cols);

    cout << "Result: " << solution3(matrix, rows, cols) << endl;

    deleteMatrix(matrix, rows);
}

// void deleteElement(int *row, int size, int index) {
//     for (int i = index; i < size - 1; i++) {
//         row[i] = row[i + 1];
//     }

//     delete row[size - 1];
// }

void solution6(int **matrix, int rows, int &cols, int k) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            
        }
    }

    cols -= 1;
}

void zad6() {
    int rows;
    cout << "Enter rows: "; cin >> rows;

    int cols;
    cout << "Enter cols: "; cin >> cols;

    int k;
    cout << "Enter k: "; cin >> k;

    int **matrix = enterMatrix(rows, cols);

    printMatrix(matrix, rows, cols);
    solution6(matrix, rows, cols, k);
    printMatrix(matrix, rows, cols);

    deleteMatrix(matrix, rows);
}

int main() {
    // zad1();
    // zad3();

    return 0;
}