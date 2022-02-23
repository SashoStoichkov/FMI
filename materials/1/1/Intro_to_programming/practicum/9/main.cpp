#include <iostream>
#include <cstring>
using namespace std;

char* myStrTok(char* str, const char* delim) {
    static char* p = NULL;
    if (str != NULL) {
        p = str;
    }
    if (p == NULL) {
        return NULL;
    }

    while (*p != '\0') {
        int i = 0;
        while (delim[i] != '\0') {
            if (*p == delim[i]) {
                *p = '\0';
                p++;
                return str;
            }
            i++;
        }
        p++;
    }

    return NULL;
}

void printWords(char *words, const char *delimiter) {
    char *word = myStrTok(words, delimiter);

    while (word != NULL) {
        cout << "'" << word << "'" << endl;
        word = myStrTok(NULL, delimiter);
    }
}

int main() {
    char words[100];

    cout << "Enter a string: ";
    cin.getline(words, 100);

    printWords(words, ", ");

    return 0;
}