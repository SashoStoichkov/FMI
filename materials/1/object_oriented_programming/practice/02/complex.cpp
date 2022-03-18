#include <iostream>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <limits>

using namespace std;

// struct for complex numbers
struct complex {
    double real;
    double imag;

    void print() const;
};

void complex::print() const {
    cout << real << " + " << imag << "i" << endl;
}

// sum of two complex numbers
complex sum(complex a, complex b) {
    complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

int main() {
    complex a, b, c;

    cout << "Enter the real and imaginary parts of the first complex number: ";
    cin >> a.real >> a.imag;

    cout << "Enter the real and imaginary parts of the second complex number: ";
    cin >> b.real >> b.imag;

    cout << "a = "; a.print();

    cout << "b = "; b.print();

    cout << "Result:" << endl;

    c = sum(a, b);
    cout << "a + b = "; c.print();

    return 0;
}
