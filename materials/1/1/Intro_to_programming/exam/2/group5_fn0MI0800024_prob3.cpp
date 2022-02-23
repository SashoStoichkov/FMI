#include <iostream>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <climits>

using namespace std;

int getIndex(char *arr, int n, char c) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == c) {
            return i;
        }
    }

    return -1; // not found
}

int calculate(char *input, int n, char *letters, int *numbers) {
    int result = 0;

    int firstNumber = 0;
    int secondNumber = 0;
    int index;

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != '.' && input[i] != '+') {
            index = getIndex(letters, n, input[i]);

            if (index > -1) {
                firstNumber = numbers[index];
            }
        } else {
            if (input[i] == '.') {
                index = getIndex(letters, n, input[i+1]);

                if (index > -1) {
                    secondNumber = numbers[index];
                }

                result += firstNumber * secondNumber;

                firstNumber = result;
                secondNumber = 0;

                i++;
            } else if (input[i] == '+') {
                index = getIndex(letters, n, input[i+1]);

                if (index > -1) {
                    secondNumber = numbers[index];
                }

                result += firstNumber + secondNumber;

                firstNumber = 0;
                secondNumber = 0;

                i++;
            }
        }
    }

    return result;
}

int main() {

    // входа поради някаква причина ми дава грешка
    char input[INT_MAX];
    cin.getline(input, INT_MAX);

    // int n; cin >> n;
    
    // char *letters = new char[n];
    // for (int i = 0; i < n; i++) {
    //     cin >> letters[i];
    // }

    // int *numbers = new int[n];
    // for (int i = 0; i < n; i++) {
    //     cin >> numbers[i];
    // }

    // cout << calculate(input, n, letters, numbers) << endl;

    // delete[] letters;
    // delete[] numbers;

    return 0;
}