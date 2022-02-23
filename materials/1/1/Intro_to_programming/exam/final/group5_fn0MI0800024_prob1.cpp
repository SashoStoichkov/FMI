#include <iostream>
#include <cstring>

using namespace std;

void printArray(char *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool charInArray(char *arr, int size, char c) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == c) {
            return true;
        }
    }

    return false;
}

int numberOfMovesForIndex(char *arr, int size, int index) {
    int moves = 0;

    for (int i = index; i < size; i++) {
        if (arr[i] == 'g') {
            moves++;
        } else if (arr[i] == 'y') {
            bool foundGreen = false;
            int nextGreenIndex;

            for (int j = i+1; j < size; j++) {
                if (arr[j] == 'g') {
                    foundGreen = true;
                    nextGreenIndex = j;
                    break;
                }
            }

            if (foundGreen) {
                i = nextGreenIndex - 1;
                moves++;
            }
        } else if (arr[i] == 'r') {
            break;
        }
    }

    return moves;
}

int main() {
    const int MAX_ARRAY_SIZE = 1024;
    char validColors[3] = {'g', 'y', 'r'};

    int n;
    cout << "Enter array size: "; cin >> n;
    while (n < 0 || n > MAX_ARRAY_SIZE) {
        cout << "Incorrect size! Try again: ";
        cin >> n;
    }

    char *colors = new char[n];
    cout << "Enter array: ";
    for (int i = 0; i < n; i++) {
        cin >> colors[i];

        while (!charInArray(validColors, 3, colors[i])) {
            cout << "Wrong color! Try again: ";
            cin >> colors[i];
        }
    }

    // printArray(colors, n);

    int maxMoves = 0;
    for (int i = 0; i < n; i++) {
        int currentIndexMoves = numberOfMovesForIndex(colors, n, i);

        if (maxMoves < currentIndexMoves) {
            maxMoves = currentIndexMoves;
        }

        // cout << i << " -> " << currentIndexMoves << endl;
    }

    cout << "Result: " << maxMoves << endl;

    delete[] colors;

    return 0;
}