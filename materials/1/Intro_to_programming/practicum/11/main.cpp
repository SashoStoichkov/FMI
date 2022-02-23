#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

bool isPalindrome(char *str, int start, int end) {
    if (start >= end) {
        return true;
    }

    if (str[start] != str[end]) {
        return false;
    }

    return isPalindrome(str, start + 1, end - 1);
}

void zad1() {
    char str[100];
    cin.getline(str, 100);

    cout << boolalpha << isPalindrome(str, 0, strlen(str) - 1) << endl;
}

bool isPresent(int *arr, int size, int element) {
    if (size == 0) {
        return false;
    }

    if (arr[size - 1] == element) {
        return true;
    }

    return isPresent(arr, size - 1, element);
}

void zad2() {
    int n; cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int element; cin >> element;

    cout << boolalpha << isPresent(arr, n, element) << endl;

    delete[] arr;
}

bool isSubstring(char *str, char *substr) {
    if (strlen(substr) == 0) {
        return true;
    }

    if (strlen(str) == 0) {
        return false;
    }

    if (str[0] == substr[0]) {
        return isSubstring(str + 1, substr + 1);
    }

    return isSubstring(str + 1, substr);
}

void zad3() {
    char str1[100];
    char str2[100];
    cin.getline(str1, 100);
    cin.getline(str2, 100);

    cout << boolalpha << isSubstring(str1, str2) << endl;
}

int findBiggest(int *arr, int size, int index) {
    if (index == size) {
        return 0;
    }

    int biggest = findBiggest(arr, size, index + 1);

    if (arr[index] > biggest) {
        biggest = arr[index];
    }

    return biggest;
}

void zad4() {
    int n; cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << findBiggest(arr, n, 0) << endl;

    delete[] arr;
}

int main() {

    // zad1();
    // zad2();
    // zad3();
    // zad4();

    return 0;
}