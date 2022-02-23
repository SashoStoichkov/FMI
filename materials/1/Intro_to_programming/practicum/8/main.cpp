#include <iostream>
using namespace std;

void task4(int arr1[], int size1, int arr2[], int size2) {
    for (int i = 0; i < size1; i++) {
        if (i % 2 == 0) {
            arr2[i] = arr1[i];
        }
    }
}

void task5(int arr1[], int size1, int arr2[], int size2) {
    for (int i = 0; i < size1; i++) {
        arr1[i] = arr1[i] + arr2[i];
        arr2[i] = arr1[i] - arr2[i];
        arr1[i] = arr1[i] - arr2[i];
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    task5(arr1, size1, arr2, size2);

    // arr1 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}