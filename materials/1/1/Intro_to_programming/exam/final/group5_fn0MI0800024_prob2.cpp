#include <iostream>
#include <cstring>

using namespace std;

void inputString(char *str, int size) {
    cin.get(); // gets \n before the input

    for (int i = 0; i < size; i++) {
        str[i] = cin.get();
    }

    str[size] = '\0';
}

void deleteArray(char **arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

bool stringInArray(char *str, char **arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        if (strcmp(str, arr[i]) == 0) {
            return true;
        }
    }

    return false;
}

// void parseString(char *str, char **words, int &wordsArrayIndex, char **validWords) {
//     for (int i = 0; i < strlen(str); i++) {
//         int tempIndex = 0;
//         char *tempWord = new char[6];

//         while (!stringInArray(tempWord, validWords, 12)) {
//             tempWord[tempIndex] = str[i++];
//             tempWord[tempIndex+1] = '\0';
//             tempIndex++;
//         }

//         cout << tempWord << endl;
//         strcpy(words[wordsArrayIndex], tempWord);
//         i--; wordsArrayIndex++;

//         delete[] tempWord;
//     }
// }

int wordToDigit(char *str) {
    if (strcmp(str, "zero") == 0) {
        return 0;
    } else if (strcmp(str, "one") == 0) {
        return 1;
    } else if (strcmp(str, "two") == 0) {
        return 2;
    } else if (strcmp(str, "three") == 0) {
        return 3;
    } else if (strcmp(str, "four") == 0) {
        return 4;
    } else if (strcmp(str, "five") == 0) {
        return 5;
    } else if (strcmp(str, "six") == 0) {
        return 6;
    } else if (strcmp(str, "seven") == 0) {
        return 7;
    } else if (strcmp(str, "eight") == 0) {
        return 8;
    } else if (strcmp(str, "nine") == 0) {
        return 9;
    } else {
        return -1;
    }
}

bool validateString(char *str) {
    char *validWords[12] = {
        "zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine", "plus", "minus"
    };

    int wordsArrayIndex = 0;
    char *words[100];

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            cout << "Incorrect string! (' ' found!) Try again: ";
            return false;
        } else {
            int tempIndex = 0;
            char *tempWord = new char[6];

            while (!stringInArray(tempWord, validWords, 12)) {
                tempWord[tempIndex] = str[i++];
                tempWord[tempIndex+1] = '\0';
                tempIndex++;
            }

            cout << tempWord << endl;
            // words[wordsArrayIndex] = tempWord;
            i--; wordsArrayIndex++;

            delete[] tempWord;
        }
    }
    
    // parseString(str, words, wordsArrayIndex, validWords);

    // for (int i = 0; i < wordsArrayIndex+1; i++) {
    //     cout << words[i] << endl;
    // }

    return true;
}

int main() {

    int n; cin >> n;
    char *str = new char[n+1];

    inputString(str, n);

    while (!validateString(str)) {
        inputString(str, n);
    }

    // cout << str << endl;

    delete[] str;

    return 0;
}