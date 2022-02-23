#include <iostream>
#include <cstring>
using namespace std;

// ZAD 6

void toUpper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

void toLower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 'a' - 'A';
        }
    }
}

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

void eraseFirst(char *str, char c) {
    int len = strlen(str);
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            for (int j = i; j < len; j++) {
                str[j] = str[j + 1];
            }
            break;
        } else {
            i++;
        }
    }
}

void eraseNth(char *str, int n, char c) {
    int len = strlen(str);
    int i = 0;
    int count = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            count++;
        }
        if (count == n) {
            for (int j = i; j < len; j++) {
                str[j] = str[j + 1];
            }
            len--;
            count = 0;
        } else {
            i++;
        }
    }
}

void eraseAll(char *str, char c) {
    int len = strlen(str);
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            for (int j = i; j < len; j++) {
                str[j] = str[j + 1];
            }
            len--;
        } else {
            i++;
        }
    }
}

void replaceFirst(char *str, char c, char d) {
    int len = strlen(str);
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            str[i] = d;
            break;
        } else {
            i++;
        }
    }
}

void replaceNth(char *str, int n, char c, char d) {
    int len = strlen(str);
    int i = 0;
    int count = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            count++;
        }
        if (count == n) {
            str[i] = d;
            count = 0;
        } else {
            i++;
        }
    }
}

void replaceAll(char *str, char c, char d) {
    int len = strlen(str);
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            str[i] = d;
        }
        i++;
    }
}

int main() {
    char str[100];
    cout << "Enter string: ";
    cin.getline(str, 100);

    cout << "String: " << str << endl;

    char copyStr1[100];
    strcpy(copyStr1, str);
    toUpper(copyStr1);
    cout << "String in upper case: " << copyStr1 << endl;

    char copyStr2[100];
    strcpy(copyStr2, str);
    toLower(copyStr2);
    cout << "String in lower case: " << copyStr2 << endl;

    char copyStr3[100];
    strcpy(copyStr3, str);
    reverse(copyStr3);
    cout << "String in reverse: " << copyStr3 << endl;

    char copyStr4[100];
    strcpy(copyStr4, str);
    eraseFirst(copyStr4, 'l');
    cout << "String without first l: " << copyStr4 << endl;

    char copyStr5[100];
    strcpy(copyStr5, str);
    eraseNth(copyStr5, 2, 'l');
    cout << "String without second l: " << copyStr5 << endl;

    char copyStr6[100];
    strcpy(copyStr6, str);
    eraseAll(copyStr6, 'l');
    cout << "String without all l: " << copyStr6 << endl;

    char copyStr7[100];
    strcpy(copyStr7, str);
    replaceFirst(copyStr7, 'l', '-');
    cout << "String with first l replaced by -: " << copyStr7 << endl;

    char copyStr8[100];
    strcpy(copyStr8, str);
    replaceNth(copyStr8, 2, 'l', '-');
    cout << "String with second l replaced by -: " << copyStr8 << endl;

    char copyStr9[100];
    strcpy(copyStr9, str);
    replaceAll(copyStr9, 'l', '-');
    cout << "String with all l replaced by -: " << copyStr9 << endl;

    return 0;
}