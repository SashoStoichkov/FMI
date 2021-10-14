#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>

using namespace std;

void task1() {
    char *name;
    cout << "Enter Name: ";
    cin >> name;


    int myAge;
    cout << "Enter Age: ";
    cin >> myAge;

    cout << "Output: " << name << endl;
    cout << myAge << " -> " << &myAge << " -> " << sizeof(myAge) << endl;
}

void task2() {
    cout << "The sizeof(int) is: " << sizeof(int) << " bytes." << endl;
    cout << "The sizeof(long) is: " << sizeof(long) << " bytes." << endl;
    cout << "The sizeof(long long) is: " << sizeof(long long) << " bytes." << endl;
    cout << "The sizeof(float) is: " << sizeof(float) << " bytes." << endl;
    cout << "The sizeof(double) is: " << sizeof(double) << " bytes." << endl;
    cout << "The sizeof(long double) is: " << sizeof(long double) << " bytes." << endl;
    cout << "The sizeof(char) is: " << sizeof(char) << " bytes." << endl;
    cout << "The sizeof(short) is: " << sizeof(short) << " bytes." << endl;
    cout << "The sizeof(bool) is: " << sizeof(bool) << " bytes." << endl;
}

void task3() {
    cout << "The minimum limit of int data type: " << INT_MIN << endl;
    cout << "The maximum limit of int data type: " << INT_MAX << endl << endl;

    cout << "The minimum limit of long data type: " << LONG_MIN << endl;
    cout << "The maximum limit of long data type: " << LONG_MAX << endl << endl;

    cout << "The minimum limit of short data type: " << SHRT_MIN << endl;
    cout << "The maximum limit of short data type: " << SHRT_MAX << endl << endl;

    cout << "The minimum limit of char data type: " << CHAR_MIN << endl;
    cout << "The maximum limit of char data type: " << CHAR_MAX << endl << endl;

    cout << "The maximum limit of unsigned int data type: " << UINT_MAX << endl << endl;
    cout << "The maximum limit of unsigned long data type: " << ULONG_MAX << endl << endl;
}

void task4() {
    int a, b;

    cout << "Enter a: "; cin >> a;
    cout << "Enter b: "; cin >> b;

    cout << endl;

    cout << "a + b = " << a + b << endl;
    cout << "|a - b| = " << abs(a - b) << endl;
    cout << "a % b = " << a % b << endl;
    cout << "a / b = " << a / b << endl;
    cout << "a / b = " << double(a) / double(b) << endl;
    int c = floor(double(a) / double(b));
    cout << "floor(a / b) = " << c << endl;
    cout << "ceil(a / b) = " << ceil(double(a) / double(b)) << endl;
    cout << "a ** sqrt(b) = " << pow(a, sqrt(b)) << endl;
    cout << fixed << setprecision(5) << "log2(c) = " << log2(c) << endl;
}

void task5() {
    double a, b;
    cin >> a >> b;
    cout << "(a = " << a << ", b = " << b << ")" << endl;

    // swap a and b using temporary variable
    double temp = a;
    a = b;
    b = temp;

    cout << "(a = " << a << ", b = " << b << ")" << endl;

    // swap a and b without using temporary variable
    a = a + b;
    b = a - b;
    a = a - b;

    cout << "(a = " << a << ", b = " << b << ")" << endl;
}

void task6() {
    unsigned int number;
    cin >> number;

    cout << number % 10;
    number /= 10;

    while (number > 0) {
        cout << "-" << number % 10;
        number /= 10;
    }

    cout << endl;
}

void task7() {
    char c;
    cin >> c;

    cout << int(c) << endl;
}

void task8() {
    double number;
    cin >> number;

    cout << int(number) << endl;
}

void task9() {
    int n;
    cin >> n;

    if ((n & (n - 1)) == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Uncomment the task you want to run

    // task1();
    // task2();
    // task3();
    // task4();
    // task5();
    // task6();
    // task7();
    // task8();
    // task9();

    return 0;
}