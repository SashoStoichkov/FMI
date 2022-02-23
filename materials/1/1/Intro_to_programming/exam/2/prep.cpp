#include <iostream>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <limits>

using namespace std;

void deleteMatrix(char **matrix, int size) {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void deleteMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Да се напише програма която по дадена матрица проверява
// колко числа в нея са палиндроми които се делят на 2

bool isPalindrom(char *stringNumber) {
    int length = strlen(stringNumber);

    for (int i = 0; i < length / 2; i++) {
        if (stringNumber[i] != stringNumber[length - i - 1]) {
            return false;
        }
    }

    return true;
}

int stringToInt(char *stringNumber) {
    int number = 0;

    for (int i = strlen(stringNumber) - 1; i >= 0; i--) {
        int digit = stringNumber[i] - '0';
        number = number * 10 + digit;
    }

    return number;
}

void printResult(char **matrix, int size) {
    int counter = 0;

    for (int i = 0; i < size; i++) {
        if (isPalindrom(matrix[i]) && stringToInt(matrix[i]) % 2 == 0) {
            counter++;
        }
    }

    cout << "Result: " << counter << endl;
}

void task1() {
    int n; cin >> n;
    char **matrix = new char*[n];

    cin.get();

    for (int i = 0; i < n; i++) {
        matrix[i] = new char[150];
        cin.getline(matrix[i], 150);
    }

    printResult(matrix, n);

    for (int i = 0; i < n; i++) {
        cout << matrix[i] << endl;
    }

    deleteMatrix(matrix, n);
}

// Да се напише програма която по дадени 2 низ-а връща низ
// със символите които се срещат само в 1 или само 2

bool charInStr(char c, char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            return true;
        }
    }

    return false;
}

void task2() {
    const int MAX_SIZE = 256;
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];

    cin.getline(str1, MAX_SIZE);
    cin.getline(str2, MAX_SIZE);

    char resultStr[MAX_SIZE * 2];

    int resultIndex = 0;
    for (int i = 0; i < strlen(str1); i++) {
        if (!charInStr(str1[i], str2)) {
            resultStr[resultIndex] = str1[i];
            resultIndex++;
        }
    }

    for (int i = 0; i < strlen(str2); i++) {
        if (!charInStr(str2[i], str1) && !charInStr(str2[i], resultStr)) {
            resultStr[resultIndex] = str2[i];
            resultIndex++;
        }
    }

    resultStr[resultIndex] = '\0';

    cout << "Result: " << resultStr << endl;
}

// Да се напише програма която по въведено 1 число
// проверява дали ако съберем 1ци-те в двоичното представяне на числата
// в 1 двумерна матрица, можем да гo получим.

int bitsInBinaryRep(int number, int bit) {
    int counter = 0;

    while (number > 0) {
        if (number % 2 == bit) {
            counter++;
        }
        number /= 2;
    }

    return counter;
}

void task3() {
    int n, targetNumber;
    cin >> targetNumber >> n;

    int numberOfOnes = 0;
    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];

        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            numberOfOnes += bitsInBinaryRep(matrix[i][j], 1);
        }
    }

    cout << boolalpha << (numberOfOnes == targetNumber) << endl;

    deleteMatrix(matrix, n);
}

// Да се напише функция, която по подадени масив arr от естествени числа
// и масив от 0 и 1 x проверява дали редицата x може да се прострои от
// нулите и 1ците от представянето на някое от числата

int numberOfElementsInArr(int *arr, int size, int el) {
    int counter = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == el) {
            counter++;
        }
    }

    return counter;
}

bool printResult4(int *numbers, int numbersSize, int *bits, int bitsSize) {
    int onesInBits = numberOfElementsInArr(bits, bitsSize, 1);
    int zerosInBits = numberOfElementsInArr(bits, bitsSize, 0);

    for (int i = 0; i < numbersSize; i++) {
        int onesInNumber = bitsInBinaryRep(numbers[i], 1);
        int zerosInNumber = bitsInBinaryRep(numbers[i], 0);

        if (onesInNumber == onesInBits && zerosInNumber == zerosInBits) {
            return true;
        }
    }

    return false;
}

void task4() {
    int n, m; cin >> n >> m;

    int *numbers = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int *bits = new int[m];
    for (int i = 0; i < m; i++) {
        cin >> bits[i];
    }

    cout << boolalpha << printResult4(numbers, n, bits, m) << endl;

    delete[] bits;
    delete[] numbers;
}

// Да се напише функция, която по подадени масив arr от естествени числа
// и масив от 0 и 1 x проверява дали редицата x отговаря на
// някое от двоичните представяния на число от масива

// Пример: {0, 1, 1} -> 11 = 0*10^2 + 1*10^1 + 1*10^0
int arrToBinary(int *arr, int size) {
    int result = 0;

    for (int i = 0; i < size; i++) {
        result += arr[i] * pow(10, size - i - 1);
    }

    return result;
}

// Пример: 3 -> 11
int intToBinary(int number) {
    int result = 0;

    while (number > 0) {
        result = (result * 10) + number % 2;
        number /= 2;
    }

    return result;
}

bool printResult5(int *numbers, int numbersSize, int *bits, int bitsSize) {
    int targetBinary = arrToBinary(bits, bitsSize);

    for (int i = 0; i < numbersSize; i++) {
        if (intToBinary(numbers[i]) == targetBinary) {
            return true;
        }
    }

    return false;
}

void task5() {
    int n, m; cin >> n >> m;

    int *numbers = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int *bits = new int[m];
    for (int i = 0; i < m; i++) {
        cin >> bits[i];
    }

    cout << boolalpha << printResult5(numbers, n, bits, m) << endl;

    delete[] bits;
    delete[] numbers;
}

int main() {

    // task1();
    // task2();
    // task3();
    // task4();
    // task5();

    return 0;
}