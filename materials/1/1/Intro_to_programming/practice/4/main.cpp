#include <iostream>
#include <cmath>
using namespace std;

void zad1() {
    unsigned int a;
    cin >> a;

    // print the numbers from 1 to a
    cout << 1;
    for (int i = 2; i <= a; i++) {
        cout << " " << i;
    }
    cout << endl;

    // find sum and product of the numbers from 1 to a
    int sum = 0;
    int product = 1;

    for (int i = 1; i <= a; i++) {
        sum += i;
        product *= i;
    }

    // print the sum and product
    cout << "sum = " << sum << endl;
    cout << "product = " << product << endl;
}

void zad2() {
    int a, b;
    cin >> a >> b;

    int min, max;
    if (a < b) {
        min = a;
        max = b;
    } else {
        min = b;
        max = a;
    }

    // find sum and product of even numbers from a to b
    int sum = 0;
    int product = 1;

    for (int i = min; i <= max; i++) {
        if (i % 2 == 0) {
            sum += i;
            product *= i;
        }
    }

    // print the sum and product
    cout << "sum = " << sum << endl;
    cout << "product = " << product << endl;
}

void zad3() {
    int a;
    cin >> a;

    if (a < 0) {
        cout << "error" << endl;
        return;
    }

    // find a!
    int factorial = 1;

    for (int i = 1; i <= a; i++) {
        factorial *= i;
    }

    // print the factorial
    cout << "factorial = " << factorial << endl;
}

void zad4() {
    int a, b;
    cin >> a >> b;

    cout << "a^b = " << pow(a, b) << endl;
}

void enumZad3() {
    // ♈ Aries (Ram): March 21–April 19
    // ♉ Taurus (Bull): April 20–May 20
    // ♊ Gemini (Twins): May 21–June 21
    // ♋ Cancer (Crab): June 22–July 22
    // ♌ Leo (Lion): July 23–August 22
    // ♍ Virgo (Virgin): August 23–September 22
    // ♎ Libra (Balance): September 23–October 23
    // ♏ Scorpius (Scorpion): October 24–November 21
    // ♐ Sagittarius (Archer): November 22–December 21
    // ♑ Capricornus (Goat): December 22–January 19
    // ♒ Aquarius (Water Bearer): January 20–February 18
    // ♓ Pisces (Fish): February 19–March 20

    // enum zodiac signs
    enum ZodiacSigns {
        Aries = 1,
        Taurus = 2,
        Gemini = 3,
        Cancer = 4,
        Leo = 5,
        Virgo = 6,
        Libra = 7,
        Scorpio = 8,
        Sagittarius = 9,
        Capricorn = 10,
        Aquarius = 11,
        Pisces = 12
    };

    // switch zodiac sign number to name
    int num;
    cin >> num;

    switch (num) {
        case Aries:
            cout << "Aries" << endl;
            break;
        case Taurus:
            cout << "Taurus" << endl;
            break;
        case Gemini:
            cout << "Gemini" << endl;
            break;
        case Cancer:
            cout << "Cancer" << endl;
            break;
        case Leo:
            cout << "Leo" << endl;
            break;
        case Virgo:
            cout << "Virgo" << endl;
            break;
        case Libra:
            cout << "Libra" << endl;
            break;
        case Scorpio:
            cout << "Scorpio" << endl;
            break;
        case Sagittarius:
            cout << "Sagittarius" << endl;
            break;
        case Capricorn:
            cout << "Capricorn" << endl;
            break;
        case Aquarius:
            cout << "Aquarius" << endl;
            break;
        case Pisces:
            cout << "Pisces" << endl;
            break;
        default:
            cout << "error" << endl;
            break;
    }
}

int main() {
    // zad1();
    // zad2();
    // zad3();
    // zad4();

    // enumZad3();

    return 0;
}