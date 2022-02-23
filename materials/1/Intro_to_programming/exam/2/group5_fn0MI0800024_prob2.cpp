#include <iostream>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <limits>

using namespace std;

bool hasDuplicateDigits(int number) {
    number = abs(number);
    int digits[10] = {0};

    while (number > 0) {
        int digit = number % 10;
        digits[digit]++;
        number /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (digits[i] > 1) {
            return true;
        }
    }

    return false;
}

int *collect(int **matrix, int matrixSize, int *resultArr, int resultArrSize) {
    int currRow = matrixSize - 1;
    int lastRow = matrixSize - 1;
    int currCol = 0;
    int lastCol = matrixSize - 1;

    int resultArrIndex = 0;

    while (resultArrIndex < resultArrSize) {
        if (currRow > matrixSize - 1) {
            currRow = lastRow - 1;
            lastRow--;
            currCol = 0;
        // } else if (currRow < 0) {
        //     currCol = lastCol - 1;
        //     lastCol--;
        //     lastRow = 0;
        } else {
            if (hasDuplicateDigits(matrix[currRow][currCol])) {
                resultArr[resultArrIndex] = matrix[currRow][currCol];
                resultArrIndex++;
            }
            currRow++;
            currCol++;
        }
    }

    return resultArr;
}

int main() {
    int n; cin >> n;
    while (n < 1 || n > 30) {
        cout << "Try again: ";
        cin >> n;
    }

    int counter = 0;

    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];

        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if (hasDuplicateDigits(matrix[i][j])) {
                counter++;
            }
        }
    }

    int *resultArr = new int[counter];

    // не обхождам матрицата добре след вторичния диагонал
    // resultArr = collect(matrix, n, resultArr, counter);

    for (int i = 0; i < counter; i++) {
        cout << resultArr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] resultArr;

    // cout << boolalpha << hasDuplicateDigits(112) << endl;

    return 0;
}