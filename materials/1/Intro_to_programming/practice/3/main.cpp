#include <iostream>
#include <cmath>
using namespace std;

void zad1() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a > b && a > c) {
        cout << a << endl;
    } else if (b > a && b > c) {
        cout << b << endl;
    } else {
        cout << c << endl;
    }
}

void zad2() {
    int a, b;
    cin >> a >> b;

    bool digit = false;

    // print digits of a
    while (a > 0) {
        if (a % 10 == b) {
            digit = true;
            break;
        }
        a /= 10;
    }

    if (digit) {
        cout << "b is a digit of a" << endl;
    } else {
        cout << "b is not a digit of a" << endl;
    }
}

void zad3() {
    int a;
    cin >> a;

    // check if there are equal digits
    bool equal = false;
    int digit = 0;
    while (a > 0) {
        if (digit == 0) {
            digit = a % 10;
        } else if (digit == a % 10) {
            equal = true;
            break;
        }
        a /= 10;
    }

    if (equal) {
        cout << "there are equal digits" << endl;
    } else {
        cout << "there are not equal digits" << endl;
    }
}

void zad4() {
    int a;
    cin >> a;

    // check if all digits are in increasing order
    bool increasing = true;
    int digit = 0;
    while (a > 0) {
        if (digit == 0) {
            digit = a % 10;
        } else if (digit < a % 10) {
            increasing = false;
            break;
        }
        a /= 10;
    }

    if (increasing) {
        cout << "all digits are in increasing order" << endl;
    } else {
        cout << "all digits are not in increasing order" << endl;
    }
}

void zad5() {
    int a, b;
    cin >> a;

    // check if a is in [1001, 8888)
    if (a >= 1001 && a < 8888) {
        cout << "a is in [1001, 8888)" << endl;

        cin >> b;

        // how many times digit b is in a
        int count = 0;
        while (a > 0) {
            if (a % 10 == b) {
                count++;
            }
            a /= 10;
        }

        cout << "digit b is in a " << count << " times" << endl;
    } else {
        cout << "a is not in [1001, 8888)" << endl;
    }
}

void zad6() {
    int a;
    cin >> a;

    // check if a is a palindrome
    int b = a;
    int c = 0;
    while (b > 0) {
        c = c * 10 + b % 10;
        b /= 10;
    }

    if (a == c) {
        cout << "a is a palindrome" << endl;
    } else {
        cout << "a is not a palindrome" << endl;
    }
}

void zad7() {
    int a;
    cin >> a;

    // a < 0 => error
    // a < 25 => 2.00
    // 25 <= a < 40 => 3.00
    // 40 <= a < 60 => 4.00
    // 60 <= a < 80 => 5.00
    // 80 <= a => 6.00

    if (a < 0) {
        cout << "error" << endl;
    } else {
        if (a < 25) {
            cout << "2.00" << endl;
        } else if (a < 40) {
            cout << "3.00" << endl;
        } else if (a < 60) {
            cout << "4.00" << endl;
        } else if (a < 80) {
            cout << "5.00" << endl;
        } else {
            cout << "6.00" << endl;
        }
    }
}

void zad8() {
    double a, b, c;
    cin >> a >> b >> c;

    // check if a, b and c can form a triangle
    if (a + b > c && a + c > b && b + c > a) {
        cout << "a, b and c can form a triangle" << endl;
    } else {
        cout << "a, b and c cannot form a triangle" << endl;
    }
}

void zad9() {
    char c;
    cin >> c;

    // check if c is small letter, capital letter or digit

    if (c >= 'a' && c <= 'z') {
        cout << "char is a small letter" << endl;
    } else if (c >= 'A' && c <= 'Z') {
        cout << "char is a capital letter" << endl;
    } else if (c >= '0' && c <= '9') {
        cout << "char is a digit" << endl;
    } else {
        cout << "char is other" << endl;
    }
}

void zad10() {
    char c;
    cin >> c;

    // print capital letter if c is small letter
    if (c >= 'a' && c <= 'z') {
        cout << (char) ('A' + c - 'a') << endl;
    } else if (c >= 'A' && c <= 'Z') {
        cout << c << endl;
    } else {
        cout << "Invalid input" << endl;
    }
}

int main() {
    // zad1();
    // zad2();
    // zad3();
    // zad4();
    // zad5();
    // zad6();
    // zad7();
    // zad8();
    // zad9();
    // zad10();

    return 0;
}