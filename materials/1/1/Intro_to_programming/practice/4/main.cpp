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

void zad5() {
    int n;
    cin >> n;

    double result = 0;

    for (int i = 1; i <= n; i++) {
        result += 1.0 / pow(i, i);
    }

    cout << "result = " << result << endl;
}

void zad6() {
    int x, n;
    cin >> x >> n;

    double result = 1;

    for (int i = 1; i < n; i++) {
        int fact = 1;

        for (int j = 1; j <= 2*i; j++) {
            fact *= j;
        }

        result += pow(-1, i) * (pow(x, 2*i) / fact);
    }

    cout << result << endl;
}

void zad7() {
    int n;
    cin >> n;

    // check if n is prime
    bool isPrime = true;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }

    cout << boolalpha << "isPrime = " << isPrime << endl;
}

void zad8() {
    int n;
    cin >> n;

    // print all factors of n
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }

    cout << endl;
}

void zad9() {
    int n;
    cin >> n;

    // prime factorization of n
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
            n /= i;
            i--;
        }
    }

    cout << endl;
}

void zad10() {
    int n;
    cin >> n;
    n = abs(n);

    // sum of digits of n
    int sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    cout << "sum = " << sum << endl;
}

void zad11() {
    int n;
    cin >> n;

    // int a with reversed digits of n
    int a = 0;

    while (n > 0) {
        a = a * 10 + n % 10;
        n /= 10;
    }

    cout << "a = " << a << endl;
}

void zad12() {
    int x;
    cin >> x;

    if (-pow(2, 31) <= x && x <= pow(2, 31) - 1) {
        // check if x is palindrome
        bool isPalindrome = true;

        int n = x;
        int a = 0;

        while (n > 0) {
            a = a * 10 + n % 10;
            n /= 10;
        }

        if (x != a) {
            isPalindrome = false;
        }

        cout << boolalpha << "isPalindrome = " << isPalindrome << endl;
    } else {
        cout << "error" << endl;
    }
}

void zad13() {
    int n, m;
    cin >> n >> m;

    // print greatest common divisor of n and m
    int gcd = 1;

    for (int i = 1; i <= n && i <= m; i++) {
        if (n % i == 0 && m % i == 0) {
            gcd = i;
        }
    }

    cout << "gcd = " << gcd << endl;
}

int main() {
    // zad1();
    // zad2();
    // zad3();
    // zad4();

    // enumZad3();

    // zad5();
    // zad6();
    // zad7();
    // zad8();
    // zad9();
    // zad10();
    // zad11();
    // zad12();
    // zad13();

    return 0;
}