#include <iostream>
#include <cmath>
using namespace std;

// https://bit.ly/12novV2021

void zad1() {
    int n;
    cin >> n;
    double numArr[n];

    for (int i = 0; i < n; i++) {
        cin >> numArr[i];
    }

    for (int i = n-1; i >= 0; i--) {
        cout << numArr[i] << " ";
    }

    cout << endl;
}

void zad2() {
    int n;
    cin >> n;

    double numArr[n];

    for (int i = 0; i < n; i++) {
        cin >> numArr[i];
    }

    // min max
    double min = numArr[0];
    double max = numArr[0];

    for (int i = 1; i < n; i++) {
        if (numArr[i] < min) {
            min = numArr[i];
        }
        if (numArr[i] > max) {
            max = numArr[i];
        }
    }

    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
}

void zad3() {
    int digits[10];

    for (int i = 0; i < 10; i++) {
        cin >> digits[i];
    }

    int countDigits[10] = {0};

    for (int i = 0; i < 10; i++) {
        countDigits[digits[i]]++;
    }

    int max = 0;
    int maxIndex = 0;

    for (int i = 0; i < 10; i++) {
        if (countDigits[i] > max) {
            max = countDigits[i];
            maxIndex = i;
        }
    }

    cout << maxIndex << " -> " << max << endl;
}

void zad4() {
    
}

int main() {
    // zad1();
    // zad2();
    // zad3();

    return 0;
}