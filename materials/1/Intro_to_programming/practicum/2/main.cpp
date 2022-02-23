#include <iostream>
#include <cmath>
using namespace std;

// https://bit.ly/10oct2021

void zad1() {
    double a;
    cout << "a = "; cin >> a;

    cout << "Square = " << 4 * a << endl;
    cout << "Circle = " << 2 * M_PI * a << endl;
    cout << "Triangle = " << 3 * a << endl;
    cout << "Triangle = " << sqrt(3) * a * a / 4 << endl;
}

void zad2() {
    char c; cin >> c;

    cout << "ASCII is " << (int)c << endl;
}

void zad3() {
    cout << char(sizeof(char) << 6) << endl;
}

void zad4() {
    int num; cin >> num;

    // digits array of num
    int digits[4];
    for (int i = 0; i < 4; i++) {
        digits[i] = num % 10;
        num /= 10;
    }

    // sum of digits
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += digits[i];
    }
    cout << sum << endl;

    // multiply of digits
    int mult = 1;
    for (int i = 0; i < 4; i++) {
        mult *= digits[i];
    }
    cout << mult << endl;

    // sum of digits / 2
    cout << sum / 2 << endl;

    // digits in reverse order
    for (int i = 0; i < 4; i++) {
        cout << digits[i];
    }

    cout << endl;
}

void zad5() {
    int num; cin >> num;

    int power = 1;
    for (int i = 0; i < num; i++) {
        power <<= 1;
    }

    cout << power << endl;
}

void zad6() {
    int a, b;
    cin >> a >> b;

    // swap a and b
    int temp = a;
    a = b;
    b = temp;

    cout << a << " " << b << endl;

    // swap a and b bitwise
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << a << " " << b << endl;
}

int main() {
    // zad1();
    // zad2();
    // zad3();
    // zad4();
    // zad5();
    // zad6();

    return 0;
}