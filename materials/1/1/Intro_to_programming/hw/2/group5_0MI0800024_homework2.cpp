#include <iostream>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <limits>

// for easier debugging in autoCorrect()
// #include <fstream>

using namespace std;

// TASK 0 ======================== autoCorrect ===========================

void seperatedWordsFromDictionary(char **dictionary, int dictionarySize, char **words) {
    char *word1, *word2;
    int index = 0;

    for (int i = 0; i < dictionarySize; i++) {
        char *entry = dictionary[i];

        for (int j = 0; j < strlen(entry); j++) {
            if (entry[j] == '-') {
                word1 = new char[j + 1];
                strncpy(word1, entry, j);
                word1[j] = '\0';

                // append word1 to words
                words[index] = new char[strlen(word1) + 1];
                strcpy(words[index], word1);
                index++;

                word2 = new char[strlen(entry) - j];
                strncpy(word2, entry + j + 1, strlen(entry) - j);
                word2[strlen(entry) - j] = '\0';

                // append word2 to words
                words[index] = new char[strlen(word2) + 1];
                strcpy(words[index], word2);
                index++;

                delete[] word1;
                delete[] word2;

                break;
            }
        }
    }

    // for (int i = 0; i < wordsArraySize; i++) {
    //     cout << words[i] << endl;
    // }
}

bool notALetter(char c) {
    return !(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z');
}

bool notANumber(char c) {
    return !(c >= '0' && c <= '9');
}

void replaceSubstringInText(char *text, char *substring, char *replacement) {
    char *temp = new char[strlen(text) + 1];
    strcpy(temp, text);

    int index = 0;
    int substringLength = strlen(substring);
    int replacementLength = strlen(replacement);

    for (int i = 0; i < strlen(text); i++) {
        if (strncmp(temp + i, substring, substringLength) == 0 && notALetter(temp[i - 1]) && notALetter(temp[i + substringLength])) {
            strncpy(text + index, replacement, replacementLength);
            index += replacementLength;
            i += substringLength - 1;
        } else {
            text[index] = temp[i];
            index++;
        }
    }

    text[index] = '\0';

    delete[] temp;
}

void fullstopCheck(char *text, char *correctedText) {
    int correctedTextIndex = 0;

    for (int i = 0; i <= strlen(text); i++) {
        if (text[i] == '\n' || text[i] == '\0') {
            if (i > 0 && text[i - 1] != '.') {
                if ((text[i - 1] == '\'' || text[i - 1] == '\"') && text[i - 2] != '.') {
                    correctedText[correctedTextIndex - 1] = '.';
                    correctedText[correctedTextIndex] = text[i - 1];
                } else {
                    correctedText[correctedTextIndex] = '.';
                }
                correctedTextIndex++;
            }
        }

        correctedText[correctedTextIndex] = text[i];
        correctedTextIndex++;
    }

    correctedText[correctedTextIndex] = '\0';
}

void dictionaryCheck(char **words, int wordsArraySize, char *correctedText) {
    for (int i = 0; i < wordsArraySize; i += 2) {
        replaceSubstringInText(correctedText, words[i], words[i + 1]);
    }
}

bool isPunctuation(char c) {
    return notALetter(c) && notANumber(c) && c != '\0' && c != '\n' && c != ' ';
}

void spacesCheck(char *correctedText) {
    int correctedTextIndex = 0;
    int correctedTextLength = strlen(correctedText);

    char *temp = new char[correctedTextLength + 1];

    bool openingQuote = true;
    bool charAlreadyAdded = false;

    for (int i = 0; i < correctedTextLength; i++) {
        char currChar = correctedText[i];

        if (isPunctuation(currChar)) {
            if (currChar == '\'' || currChar == '\"') {
                if (openingQuote) {
                    // check for space before opening quote - if there is none, add one
                    if (i > 0 && correctedText[i - 1] != ' ') {
                        temp[correctedTextIndex] = ' ';
                        correctedTextIndex++;
                    }

                    // check for space after opening quote - if there is one, remove it
                    if (i < correctedTextLength - 1 && correctedText[i + 1] == ' ') {
                        i++;
                    }
                } else {
                    // check for space before closing quote - if there is one, remove it
                    if (i > 0 && correctedText[i - 1] == ' ') {
                        i--;
                    }

                    // check for space after closing quote - if there is none, add it
                    if (i < correctedTextLength - 1 && correctedText[i + 1] != ' ') {
                        temp[correctedTextIndex] = ' ';
                        correctedTextIndex++;
                    }
                }

                openingQuote = !openingQuote;
            } else {
                // check for space after punctuation - if there is none, add one
                if (i < correctedTextLength - 1 && correctedText[i + 1] != ' ') {
                    temp[correctedTextIndex] = currChar;
                    temp[correctedTextIndex + 1] = ' ';
                    correctedTextIndex++;
                    charAlreadyAdded = true;
                }
            }
        }

        if (charAlreadyAdded) {
            charAlreadyAdded = false;
        } else {
            temp[correctedTextIndex] = currChar;
            correctedTextIndex++;
        }
    }

    temp[correctedTextIndex] = '\0';

    strcpy(correctedText, temp);
    delete[] temp;
}

void autoCorrect(char *text, char **dictionary, int dictionarySize) {
    const int MAX_TEXT_LENGTH_AFTER_CORRECTION = 2048;
    char *correctedText = new char[MAX_TEXT_LENGTH_AFTER_CORRECTION];

    int wordsArraySize = dictionarySize * 2;
    char **words = new char*[wordsArraySize];
    seperatedWordsFromDictionary(dictionary, dictionarySize, words);

    fullstopCheck(text, correctedText);
    dictionaryCheck(words, wordsArraySize, correctedText);
    spacesCheck(correctedText);

    // ofstream inputFile;
    // inputFile.open("input.txt");
    // inputFile << text;
    // inputFile.close();

    // for easier debugging
    // ofstream outputFile;
    // outputFile.open("output.txt");
    // outputFile << correctedText;
    // outputFile.close();

    cout << "Corrected text:" << endl << correctedText << endl;

    for (int i = 0; i <= wordsArraySize; i++) {
        delete[] words[i];
    }
    delete[] words;
    delete[] correctedText;
}

void demoTask0() {
    char text[] = "Once upon a time there lived in a certain village a little country girl, the pritiest creature who was ever seen. Her mother was excessively fond of her; and her grandmother doted on her still more.This good woman had a little red riding hood made for her. It suited the girl so extremely well that everybody called her little red riding hood.\nOne day her mother, having made some cakes, said to her,\"Go, my dear, and see how your grandmother is doing, for I hear she has been very ill. Take her a cake, and this little pot of butter\"\0";
    char *dictionary[] = {"stil-still", "pritiest-prettiest", "little red riding hood-Little Red Riding Hood", "leafes-leaves"};

    autoCorrect(text, dictionary, 4);
}

void task0() {
    const int MAX_TEXT_LENGTH = 1024;
    const int MAX_DICTIONARY_SIZE = 128;
    const int MAX_DICTIONARY_ENTRY_LENGTH = 100;

    int textLength, dictionarySize;

    cout << "Enter text length: ";

    cin >> textLength;
    while (textLength > MAX_TEXT_LENGTH || textLength <= 0) {
        cout << "Text length is invalid. Try again." << endl;
        cin >> textLength;
    }

    cin.get();

    char *text = new char[textLength+1];

    for (int i = 0; i < textLength; i++) {
        text[i] = cin.get();
    }
    text[textLength] = '\0';

    cout << "Enter dictionary size: ";

    cin >> dictionarySize;
    while (dictionarySize > MAX_DICTIONARY_SIZE || dictionarySize <= 0) {
        cout << "Dictionary size is invalid. Try again." << endl;
        cin >> dictionarySize;
    }

    cin.get();

    char **dictionary = new char*[dictionarySize];
    for (int i = 0; i < dictionarySize; i++) {
        dictionary[i] = new char[MAX_DICTIONARY_ENTRY_LENGTH];
        cin.getline(dictionary[i], MAX_DICTIONARY_ENTRY_LENGTH);
    }

    // cout << text << endl;
    // for (int i = 0; i < dictionarySize; i++) {
    //     cout << dictionary[i] << endl;
    // }

    autoCorrect(text, dictionary, dictionarySize);

    for (int i = 0; i < dictionarySize; i++) {
        delete[] dictionary[i];
    }
    delete[] dictionary;
    delete[] text;
}

// TASK 1 ===================== transformMatrix ==========================

void deleteMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void resizeMatrix(int **&matrix, int rows, int cols, int newRows, int newCols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > newRows) {
                delete[] matrix[i];
            } else {
                if (j > newCols) {
                    void *temp = realloc(matrix[i], newCols * sizeof(int));

                    if (temp == NULL) {
                        cout << "Error: realloc failed" << endl;
                        exit(1);
                    }

                    matrix[i] = (int *)temp;
                }
            }
        }
    }
}

void transformMatrix(int **matrixA, int **matrixB, int N1, int M1, int N2, int M2) {
    int minRows = min(N1, N2);
    int minCols = min(M1, M2);

    resizeMatrix(matrixA, N1, M1, minRows, minCols);

    for (int i = 0; i < minRows; i++) {
        for (int j = 0; j < minCols; j++) {
            if (matrixA[i][j] < matrixB[i][j]) {
                matrixA[i][j] = matrixB[i][j];
            } else if (matrixA[i][j] > matrixB[i][j]) {
                matrixA[i][j] *= -1;
            }
        }
    }

    cout << "Transformed Matrix A:" << endl;
    printMatrix(matrixA, minRows, minCols);
}

void demoTask1() {
    int **matrixA = new int*[4];

    int rowA1[] = {1, 2, 3, -4};
    int rowA2[] = {10, 19, 2, 0};
    int rowA3[] = {-5, 0, 2, 1};

    matrixA[0] = rowA1;
    matrixA[1] = rowA2;
    matrixA[2] = rowA3;

    int **matrixB = new int*[3];

    int rowB1[] = {1, -3, 8, 10, 34};
    int rowB2[] = {4, 7, 13, 2, 9};
    int rowB3[] = {3, 0, -4, 5, 2};

    matrixB[0] = rowB1;
    matrixB[1] = rowB2;
    matrixB[2] = rowB3;

    // cout << "Matrix A:" << endl;
    // printMatrix(matrixA, 3, 4);

    // cout << "Matrix B:" << endl;
    // printMatrix(matrixB, 3, 5);

    transformMatrix(matrixA, matrixB, 4, 4, 3, 5);

    delete[] matrixA;
    delete[] matrixB;
}

void task1() {
    int N1, M1, N2, M2;

    cout << "Enter matrixA & matrixB dimensions: ";
    cin >> N1 >> M1 >> N2 >> M2;

    cout << "Enter matrixA:" << endl;
    int **matrixA = new int*[N1];
    for (int i = 0; i < N1; i++) {
        matrixA[i] = new int[M1];
        for (int j = 0; j < M1; j++) {
            cin >> matrixA[i][j];
        }
    }

    cout << "Enter matrixB:" << endl;
    int **matrixB = new int*[N2];
    for (int i = 0; i < N2; i++) {
        matrixB[i] = new int[M2];
        for (int j = 0; j < M2; j++) {
            cin >> matrixB[i][j];
        }
    }

    cout << endl;

    // cout << "Matrix A:" << endl;
    // printMatrix(matrixA, N1, M1);

    // cout << "Matrix B:" << endl;
    // printMatrix(matrixB, N2, M2);

    transformMatrix(matrixA, matrixB, N1, M1, N2, M2);

    deleteMatrix(matrixA, N1);
    deleteMatrix(matrixB, N2);
}

// TASK 2 ======================= LanguageWords ==========================

bool checkIfWordIsInLanguage(char *word);

int indexOf(char c, char *word, int wordLength) {
    for (int i = 0; i < wordLength; i++) {
        if (word[i] == c) {
            return i;
        }
    }

    return -1; // not found
}

bool everyCharIs(char c, char *word, int wordLength) {
    for (int i = 0; i < wordLength; i++) {
        if (word[i] != c) {
            return false;
        }
    }

    return true;
}

bool checkForAAB(char *word, int wordLength) {
    char *subWord = strncpy(new char[wordLength - 2], word + 2, wordLength - 3);
    subWord[wordLength - 3] = '\0';

    return checkIfWordIsInLanguage(subWord);
}

bool checkForD(char *word, int wordLength) {
    int halfIndex = int(wordLength / 2);

    char *subWord1 = strncpy(new char[halfIndex], word, halfIndex);
    subWord1[halfIndex] = '\0';

    char *subWord2 = strncpy(new char[halfIndex], word + halfIndex + 1, halfIndex);
    subWord2[halfIndex] = '\0';

    if (strcmp(subWord1, subWord2) == 0) {
        return checkIfWordIsInLanguage(subWord1);
    } else {
        return false;
    }
}

bool checkForC(char *word, int wordLength) {
    int indexOfC = indexOf('C', word, wordLength);

    char *subWord1 = strncpy(new char[indexOfC], word, indexOfC);
    subWord1[indexOfC] = '\0';

    char *subWord2 = strncpy(new char[wordLength - indexOfC], word + indexOfC + 1, wordLength - indexOfC - 1);
    subWord2[wordLength - indexOfC] = '\0';

    return checkIfWordIsInLanguage(subWord1) && checkIfWordIsInLanguage(subWord2);
}

int caseN(int caseN, char *word, int wordLength) {
    int currCase = 0;

    switch (caseN) {
        case 0:
            if (wordLength >= 3 && word[0] == 'A' && word[1] == 'A' && word[wordLength - 1] == 'B') {
                currCase = checkForAAB(word, wordLength);
            } else if (indexOf('D', word, wordLength) == int(wordLength / 2)) {
                currCase = checkForD(word, wordLength);
            } else if (indexOf('C', word, wordLength) >= 0 && indexOf('C', word, wordLength) < wordLength) {
                currCase = checkForC(word, wordLength);
            }
            break;

        case 1:
            if (wordLength >= 3 && word[0] == 'A' && word[1] == 'A' && word[wordLength - 1] == 'B') {
                currCase = checkForAAB(word, wordLength);
            } else if (indexOf('C', word, wordLength) >= 0 && indexOf('C', word, wordLength) < wordLength) {
                currCase = checkForC(word, wordLength);
            } else if (indexOf('D', word, wordLength) == int(wordLength / 2)) {
                currCase = checkForD(word, wordLength);
            }
            break;

        case 2:
            if (indexOf('C', word, wordLength) >= 0 && indexOf('C', word, wordLength) < wordLength) {
                currCase = checkForC(word, wordLength);
            } else if (wordLength >= 3 && word[0] == 'A' && word[1] == 'A' && word[wordLength - 1] == 'B') {
                currCase = checkForAAB(word, wordLength);
            } else if (indexOf('D', word, wordLength) == int(wordLength / 2)) {
                currCase = checkForD(word, wordLength);
            }
            break;

        case 3:
            if (indexOf('C', word, wordLength) >= 0 && indexOf('C', word, wordLength) < wordLength) {
                currCase = checkForC(word, wordLength);
            } else if (indexOf('D', word, wordLength) == int(wordLength / 2)) {
                currCase = checkForD(word, wordLength);
            } else if (wordLength >= 3 && word[0] == 'A' && word[1] == 'A' && word[wordLength - 1] == 'B') {
                currCase = checkForAAB(word, wordLength);
            }
            break;

        case 4:
            if (indexOf('D', word, wordLength) == int(wordLength / 2)) {
                currCase = checkForD(word, wordLength);
            } else if (wordLength >= 3 && word[0] == 'A' && word[1] == 'A' && word[wordLength - 1] == 'B') {
                currCase = checkForAAB(word, wordLength);
            } else if (indexOf('C', word, wordLength) >= 0 && indexOf('C', word, wordLength) < wordLength) {
                currCase = checkForC(word, wordLength);
            }
            break;

        case 5:
            if (indexOf('D', word, wordLength) == int(wordLength / 2)) {
                currCase = checkForD(word, wordLength);
            } else if (indexOf('C', word, wordLength) >= 0 && indexOf('C', word, wordLength) < wordLength) {
                currCase = checkForC(word, wordLength);
            } else if (wordLength >= 3 && word[0] == 'A' && word[1] == 'A' && word[wordLength - 1] == 'B') {
                currCase = checkForAAB(word, wordLength);
            }
            break;

        default:
            break;
    }

    return currCase;
}

bool checkIfWordIsInLanguage(char *word) {
    int wordLength = strlen(word);

    if (wordLength == 0) {
        return true;
    } else if (wordLength > 64) {
        return false;
    } else {
        if (everyCharIs('C', word, wordLength)) {
            return true;
        } else if (everyCharIs('D', word, wordLength)) {
            return wordLength % 2 != 0;
        } else {
            for (int i = 0; i < 6; i++) {
                if (caseN(i, word, wordLength) == 1) {
                    return true;
                }
            }
        }
    }

    return false;
}

void printResult(char **words, int wordsLength) {
    cout << endl << "Result:" << endl;
    for (int i = 0; i < wordsLength; i++) {
        cout << words[i] << ": " << checkIfWordIsInLanguage(words[i]) << endl;
    }
}

void demoTask2() {
    // demo 1
    cout << "DEMO 1:" << endl;
    cout << checkIfWordIsInLanguage("AABCAAB") << endl;
    cout << checkIfWordIsInLanguage("DD") << endl;
    cout << checkIfWordIsInLanguage("AABD") << endl;
    cout << checkIfWordIsInLanguage("CAAB") << endl;
    cout << checkIfWordIsInLanguage("DDD") << endl;

    // demo 2
    cout << endl << "DEMO 2:" << endl;
    cout << checkIfWordIsInLanguage("AAAABB") << endl;
    cout << checkIfWordIsInLanguage("AACB") << endl;
    cout << checkIfWordIsInLanguage("CCCC") << endl;
    cout << checkIfWordIsInLanguage("CCDCCCAAB") << endl;
    cout << checkIfWordIsInLanguage("AABAAB") << endl;
    cout << checkIfWordIsInLanguage("CAABDAAB") << endl;
    cout << checkIfWordIsInLanguage("AABCDAAB") << endl;
    cout << checkIfWordIsInLanguage("") << endl;
    cout << checkIfWordIsInLanguage("CXC") << endl;
    cout << checkIfWordIsInLanguage("AABAAAABB") << endl;
}

void task2() {
    int MAX_WORD_COUNT = 1024;
    int MAX_WORD_LENGTH = 256;

    int wordCount; cin >> wordCount;
    while (wordCount > MAX_WORD_COUNT || wordCount <= 0) {
        cout << "Word count is invalid. Try again." << endl;
        cin >> wordCount;
    }

    cin.get();

    char **words = new char *[wordCount];

    for (int i = 0; i < wordCount; i++) {
        char *word = new char[MAX_WORD_LENGTH];
        cin.getline(word, MAX_WORD_LENGTH);

        words[i] = word;
    }

    printResult(words, wordCount);

    for (int i = 0; i < wordCount; i++) {
        delete[] words[i];
    }
    delete[] words;
}

// END OF TASKS =================== Have a nice day :) ===================

int main() {

    cout << "============== NOTE: Demo tasks are run automatically =================" << endl;

    cout << "TASK 0 ======================== autoCorrect ===========================" << endl;
    // task0();
    demoTask0();

    cout << "TASK 1 ===================== transformMatrix ==========================" << endl;
    // task1();
    demoTask1();

    cout << "TASK 2 ======================= LanguageWords ==========================" << endl;
    // task2();
    demoTask2();

    cout << "=================== END OF TASKS :) Have a nice day ===================" << endl;

    return 0;
}