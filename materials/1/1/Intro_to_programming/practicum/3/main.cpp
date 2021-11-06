#include <iostream>
#include <cmath>
using namespace std;

// https://bit.ly/25OCT2021

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

struct Point {
    double x, y;
};

bool operator==(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}

struct Rectangle {
    Point p1, p2, p3, p4;
};

bool operator==(Rectangle a, Rectangle b) {
    return a.p1 == b.p1 && a.p2 == b.p2 && a.p3 == b.p3 && a.p4 == b.p4;
}

bool operator<=(Rectangle a, Rectangle b) {
    return (a.p1.x >= b.p1.x && a.p1.y >= b.p1.y) &&
           (a.p2.x <= b.p2.x && a.p2.y >= b.p2.y) &&
           (a.p3.x <= b.p3.x && a.p3.y <= b.p3.y) &&
           (a.p4.x >= b.p4.x && a.p4.y <= b.p4.y);
}

Rectangle createRectangle(Point p1, Point p2) {
    Rectangle r;

    if (p1.x < p2.x) {
        if (p1.y < p2.y) {
            r = {p1, {p2.x, p1.y}, p2, {p1.x, p2.y}};
        } else {
            r = {{p1.x, p2.y}, p2, {p2.x, p1.y}, p1};
        }
    } else {
        if (p1.y < p2.y) {
            r = {{p2.x, p1.y}, p1, {p1.x, p2.y}, p2};
        } else {
            r = {p2, {p1.x, p2.y}, p1, {p2.x, p1.y}};
        }
    }

    return r;
}

void zad8() {
    Point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

    // rectangle r1 with diagonal a-b
    Rectangle r1 = createRectangle(a, b);

    // rectangle r2 with diagonal c-d
    Rectangle r2 = createRectangle(c, d);

    if (r1 == r2) {
        cout << "r1 and r2 are equal" << endl;
    } else {
        cout << "r1 and r2 are not equal" << endl;

        if (r1 <= r2) {
            cout << "r1 is inside r2" << endl;
        } else if (r2 <= r1) {
            cout << "r2 is inside r1" << endl;
        } else {
            cout << "r1 and r2 are not overlapping" << endl;
        }
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

    return 0;
}