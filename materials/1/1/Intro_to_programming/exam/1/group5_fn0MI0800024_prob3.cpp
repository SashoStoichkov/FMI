#include <iostream>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <limits>

using namespace std;

bool areEqual(int size1, int size2, char firstArr[], char seccondArr[]) {
    if (size1 != size2) {
        return false;
    } else {
        for (int i = 0; i < size1; i++) {
            if (firstArr[i] != seccondArr[i]) {
                return false;
            }
        }

        return true;
    }
}

void result(int size1, int size2, char firstArr[], char seccondArr[]) {
    if (areEqual(size1, size2, firstArr, seccondArr)) {
        cout << "Arrays are equal." << endl;
    } else {
        // char allRotations[size][size];

        // for (int i = 0; i < size2; i++) {
        //     for (int j = 0; j < size2; j++) {
        //         allRotations[i][j] = seccondArr[j];
        //     }
        // }

        // check if any rotation is subarray of firstArr
        // print suitable message
        cout << "Time's up :(" << endl;
    }
}

int main() {
    const int MAX_SIZE = 1024;
    char firstArr[MAX_SIZE], seccondArr[MAX_SIZE];

    int size1, size2;
    cin >> size1 >> size2;

    if (size1 < size2 || size1 >= MAX_SIZE || size2 >= MAX_SIZE || size1 <= 0 || size2 <= 0) {
        cout << "Wrong input of sizes!" << endl;
    } else {
        for (int i = 0; i < size1; i++) {
            cin >> firstArr[i];
        }

        for (int i = 0; i < size2; i++) {
            cin >> seccondArr[i];
        }

        result(size1, size2, firstArr, seccondArr);
    }

    return 0;
}