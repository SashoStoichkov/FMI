#include <iostream>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <limits>

using namespace std;

int digitCount(int number) {
    int count = 0;

    while (number > 0) {
        count++;
        number /= 10;
    }

    return count;
}

bool isAdjacent(int number) {
    const int SIZE = digitCount(number);
    int digits[SIZE];

    for (int i = 0; i < SIZE; i++) {
        digits[i] = number % 10;
        number /= 10;
    }

    for (int i = 0; i < SIZE - 1; i++) {
        if (digits[i] == digits[i+1]) {
            return false;
        }
    }

    return true;
}

void result(int a, int b) {
    const int SIZE = 1000;
    int adjacent[SIZE];
    int count = 0;

    for (int i = a; i <= b; i++) {
        if (isAdjacent(i)) {
            adjacent[count] = i;
            count++;
        }
    }

    if (count == 0) {
        cout << "No adjacent numbers!" << endl;
    } else {
        int result = adjacent[count - 1] - adjacent[0];
        cout << "Result: " << result << endl;
    }
}

int main() {

    int a, b;
    cin >> a >> b;

    if (a < b) {
        result(a, b);
    } else {
        cout << "Error - a must be less than b!" << endl;
    }

    return 0;
}