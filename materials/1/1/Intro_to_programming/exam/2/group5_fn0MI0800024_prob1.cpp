#include <iostream>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <climits>

using namespace std;

bool charIsValid(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

char *minWord(char *input) {
    char currWord[INT_MAX];
    int currWordIndex = 0;
    int resultIndex = 0;

    for (int i = 0; i < strlen(input); i++) {
        if (charIsValid(input[i])) {
            // add it to a potential minWord
            currWord[currWordIndex] = input[i];
            currWordIndex++;
        } else {
            // if (strcmp())
            // add '\0' and check if is the minWord
        }
    }
}

int main() {

    // първия път като го писах работеше входа, след това ми дава грешка

    char input[INT_MAX];
    cin.getline(input, INT_MAX);

    // cout << input << endl;

    return 0;
}