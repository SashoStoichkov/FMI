#include <iostream>
#include <cmath>
using namespace std;

void zad1() {
    double a, b, c;
    cin >> a >> b >> c;

    // check if a is in the interval [b, c]
    if (a >= b && a <= c) {
        cout << "a is in the interval [b, c]" << endl;
    } else {
        cout << "a is not in the interval [b, c]" << endl;
    }
}

void zad2() {
    double a, b, c;
    cin >> a >> b >> c;

    // check if a, b and c can form a triangle
    if (a + b > c && a + c > b && b + c > a) {
        cout << "a, b and c can form a triangle" << endl;
    } else {
        cout << "a, b and c cannot form a triangle" << endl;
    }
}

void zad3() {
    char a, b, c;
    cin >> a >> b >> c;

    // print characters in alphabetical order
    if (a < b && a < c) {
        cout << a;
        if (b < c) {
            cout << b << c;
        } else {
            cout << c << b;
        }
    } else if (b < a && b < c) {
        cout << b;
        if (a < c) {
            cout << a << c;
        } else {
            cout << c << a;
        }
    } else {
        cout << c;
        if (a < b) {
            cout << a << b;
        } else {
            cout << b << a;
        }
    }

    cout << endl;
}

void zad4() {
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

void zad5() {
    double a, b, c;
    cin >> a >> b >> c;

    // find quadratic equation roots
    double d = b * b - 4 * a * c;

    if (d < 0) {
        cout << "no real roots" << endl;
    } else if (d == 0) {
        cout << "x = " << -b / (2 * a) << endl;
    } else {
        cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << endl;
        cout << "x2 = " << (-b - sqrt(d)) / (2 * a) << endl;
    }
}

void zad6() {
    int a, b;
    cin >> a >> b;

    int b1 = b;

    int digits_a[4];
    for (int i = 0; i < 4; i++) {
        digits_a[i] = a % 10;
        a /= 10;
    }

    // reverse array
    for (int i = 0; i < 4 / 2; i++) {
        int temp = digits_a[i];
        digits_a[i] = digits_a[4 - i - 1];
        digits_a[4 - i - 1] = temp;
    }

    int digits_b[2];
    for (int i = 0; i < 2; i++) {
        digits_b[i] = b % 10;
        b /= 10;
    }

    // reverse array
    for (int i = 0; i < 2 / 2; i++) {
        int temp = digits_b[i];
        digits_b[i] = digits_b[2 - i - 1];
        digits_b[2 - i - 1] = temp;
    }

    int c = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            if (digits_a[i] == digits_b[j]) {
                c = c * 10 + digits_a[i];
            }
        }
    }

    cout << (c == b1) << endl;
}

void zad7() {
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

int main() {
    // zad1();
    // zad2();
    // zad3();
    // zad4();
    // zad5();
    // zad6();
    // zad7();

    return 0;
}