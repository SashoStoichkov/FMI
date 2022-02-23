#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void inputArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArrayInReverse(int *arr, int index) {
    if (index == 0) {
        cout << endl;
        return;
    }

    cout << arr[index - 1] << " ";
    printArrayInReverse(arr, index - 1);
}

void printEvenNumbers(int *arr, int size, int index) {
    if (index == size) {
        cout << endl;
        return;
    }

    if (arr[index] % 2 == 0) {
        cout << arr[index] << " ";
    }

    printEvenNumbers(arr, size, index + 1);
}

void zad6() {
    int n; cin >> n;
    int *arr = new int[n];
    inputArray(arr, n);

    printArrayInReverse(arr, n);
    printEvenNumbers(arr, n, 0);

    delete[] arr;
}

int pellNumber(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else if (n > 1) {
        return 2 * pellNumber(n - 1) + pellNumber(n - 2);
    } else {
        return -1; // error
    }
}

void zad7() {
    int n; cin >> n;

    cout << pellNumber(n) << endl;
}

int sumOfIntArray(int *arr, int size, int index) {
    if (index == size) {
        return 0;
    }

    return arr[index] + sumOfIntArray(arr, size, index + 1);
}

void zad8() {
    int n; cin >> n;
    int *arr = new int[n];
    inputArray(arr, n);

    cout << sumOfIntArray(arr, n, 0) << endl;

    delete[] arr;
}

void printMinMax(int *arr, int size, int index, int min, int max) {
    if (index == size) {
        cout << "MIN: " << min << " | MAX: " << max << endl;
        return;
    }

    if (arr[index] < min) {
        min = arr[index];
    }

    if (arr[index] > max) {
        max = arr[index];
    }

    printMinMax(arr, size, index + 1, min, max);
}

void zad9() {
    int n; cin >> n;
    int *arr = new int[n];
    inputArray(arr, n);

    printMinMax(arr, n, 0, arr[0], arr[0]);

    delete[] arr;
}

int main() {
    // zad6();
    zad7();
    // zad8();
    // zad9();

    return 0;
}