#include <iostream>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <limits>

using namespace std;

// TASK 0 ========================= FMI point ============================

bool inCircle(double x, double y) {
    // Circle with center 0, 0 and radius 4
    return (pow(x, 2) + pow(y, 2) < pow(4, 2));
}

bool inGraySection(double x, double y) {
    return (x > -2 && x < 2 && y > -7 && y < -6);
}

double tangent(double x, double y) {
    return y / x;
}

void task0() {
    double x, y;
    cout << "Enter x and y: ";
    cin >> x >> y;

    if (inGraySection(x, y)) {
        cout << "Point is in the gray section" << endl;
    } else if (inCircle(x, y)) {
        cout << "Point is in the circle" << endl;

        // Using Pythagorean theorem
        // a^2 + b^2 = c^2, but a = b => 2a^2 = c^2 => a = sqrt(c^2 / 2)
        double coordinate = sqrt(pow(4, 2) / 2); // = 2.82843 or 2sqrt(2)

        if (x > 0) {
            cout << "Point is in the right half of the circle" << endl;

            if (x > coordinate) {
                cout << "Point is in the pirple section" << endl;
            } else {
                if (tangent(x, y) > 1) {
                    cout << "Point is in the green section" << endl;
                } else if (tangent(x, y) < 1) {
                    cout << "Point is in the yellow section" << endl;
                } else {
                    cout << "Point is not in any sector" << endl;
                }
            }
        } else {
            if (x <= -coordinate) {
                cout << "Point is not in any sector" << endl;
            } else {
                cout << "Point is in the left half of the circle" << endl;

                if (tangent(x, y) < -1) {
                    cout << "Point is in the red section" << endl;
                } else if (tangent(x, y) > 1) {
                    cout << "Point is in the blue section" << endl;
                } else if (tangent(x, y) > -1 && tangent(x, y) < 1) {
                    cout << "Point is in the pink section" << endl;
                } else {
                    cout << "Point is not in any sector" << endl;
                }
            }
        }
    } else {
        cout << "Point is not in any sector" << endl;
    }
}

// TASK 1 ========================= f_35(x) ==============================

void task1() {
    int x;
    cout << "Enter x: ";
    cin >> x;

    int result = x;
    cout << endl << "f_1(" << x << ") = " << result << endl;

    for (int i = 1; i < 35; i++) {

        if (result % 2 == 0) {
            result /= 2;
        } else {
            result = 3 * result + 1;
        }

        cout << "f_" << i+1 << "(" << x << ") = " << result << endl;
    }

    cout << endl << "Result:" << endl << "f_35(" << x << ") = " << result << endl;
}

// TASK 2 ========================= Marmalade ============================

void task2() {
    int digits;
    cout << "Enter number of digits: ";
    cin >> digits;

    while (digits % 8 != 0) {
        cout << "Number of digits is not divisible by 8! Try again: ";
        cin >> digits;
    }

    int countPeach = 0;
    int countBlueberry = 0;
    int countRosaCanina = 0;

    for (int i = 0; i < digits / 8; i++) {
        int digit;
        int code = 0;

        // First 3 digits
        for (int j = 0; j < 3; j++) {
            cin >> digit;
        }

        // Code - 4 digits
        for (int j = 0; j < 4; j++) {
            cin >> digit;
            code = code * 10 + digit;
        }

        if (i == 0) {
            cout << endl;
        }

        cout << "Code: " << code;

        // Check code
        if (code % 7 == 0) {
            cout << " % 7 = 0 -> Blueberry (+1)" << endl;
            countBlueberry++;
        } else if (code % 13 == 0) {
            cout << " % 13 = 0 -> Peach (+1)" << endl;
            countPeach++;
        } else if (code % 17 == 0) {
            cout << " % 17 = 0 -> Rosa Canina (+1)" << endl;
            countRosaCanina++;
        } else {
            cout << " -> Not found" << endl;
        }

        // Last digit
        cin >> digit;
    }

    cout << endl << "Result: " << endl;
    cout << "Blueberry: " << countBlueberry << endl;
    cout << "Peach: " << countPeach << endl;
    cout << "Rosa Canina: " << countRosaCanina << " // превод на шипка от Wikipedia :)" << endl;
}

// TASK 3 ========================= Interesting number ===================

bool isInteresting(int num) {
    num = abs(num);
    bool interesting = true;

    bool currentDigitIsEven = true;
    bool nextDigitIsEven = true;

    while (num > 0) {
        int digit = num % 10;
        currentDigitIsEven = (digit % 2 == 0);

        if (num / 10 != 0) {
            int nextDigit = (num / 10) % 10;
            nextDigitIsEven = (nextDigit % 2 == 0);

            if (currentDigitIsEven == nextDigitIsEven) {
                interesting = false;
                break;
            }
        }

        num /= 10;
    }

    return interesting;
}

void task3() {
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;

    while (a > b) {
        cout << "a must be less than b! Try again: ";
        cin >> a >> b;
    }

    int sum = 0;

    cout << endl << "Result: " << endl;
    cout << "Interesting numbers in range [" << a << ", " << b << "] = ";

    for (int i = a; i <= b; i++) {
        if (isInteresting(i)) {
            cout << i << " ";
            sum += i;
        }
    }

    cout << endl << "Sum of interesting numbers in range [" << a << ", " << b << "] = " << sum << endl;
}

// TASK 4 ========================= Bulls & Cows =========================

bool inArray(int num, int array[]) {
    bool inArray = false;

    for (int i = 0; i < 4; i++) {
        if (array[i] == num) {
            inArray = true;
            break;
        }
    }

    return inArray;
}

bool hasDifferentDigits(int num) {
    bool differentDigits = true;

    int digits[4];
    for (int i = 0; i < 4; i++) {
        digits[i] = num % 10;
        num /= 10;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (digits[i] == digits[j]) {
                differentDigits = false;
                break;
            }
        }
    }

    return differentDigits;
}

int generateSecretNumber() {
    int secretNumber = 0;
    int digits[4] = {0};
    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        int digit;

        do {
            digit = rand() % 9 + 1;
        } while (inArray(digit, digits));

        digits[i] = digit;

        secretNumber = secretNumber * 10 + digit;
    }

    return secretNumber;
}

void task4() {
    const int N = 10;

    int secretNumber = generateSecretNumber();
    int guessNumber;
    bool guessed = false;

    cout << "A secret 4-digit number is generated." << endl;
    cout << "You have " << N << " attempts to guess it." << endl;

    for (int i = 0; i < N; i++) {

        if (N - i == 1) {
            cout << "Last attempt! Enter your guess: ";
        } else {
            cout << "You have " << N - i << " attempts left! Enter your guess: ";
        }

        cin >> guessNumber;

        while (guessNumber < 1000 || guessNumber > 9999) {
            cout << "Your guess is not a 4-digit number! Try again: ";
            cin >> guessNumber;
        }

        while (!hasDifferentDigits(guessNumber)) {
            cout << "Your guess has equal digits! Try again: ";
            cin >> guessNumber;
        }

        cout << endl;

        if (guessNumber == secretNumber) {
            guessed = true;
            break;
        } else {
            int secret = secretNumber;

            int secretDigits[4] = {0};
            for (int i = 0; i < 4; i++) {
                secretDigits[i] = secret % 10;
                secret /= 10;
            }

            secret = secretNumber;
            int guess = guessNumber;

            int bulls = 0;
            int cows = 0;

            while (secret > 0) {
                int digitSecret = secret % 10;
                int digitGuess = guess % 10;

                if (digitSecret == digitGuess) {
                    bulls++;
                } else if (inArray(digitGuess, secretDigits)) {
                    cows++;
                }

                secret /= 10;
                guess /= 10;
            }

            if (N - i != 1) {
                cout << guessNumber << ": ";
                cout << "Bulls: " << bulls << " / " << "Cows: " << cows << endl;
            }
        }
    }

    cout << endl;

    if (guessed) {
        cout << "You win!" << endl;
        cout << "Secret number was indeed: " << secretNumber << endl;
    } else {
        cout << "I'm better than you :)" << endl;
        cout << "Secret number was: " << secretNumber << endl;
    }
}

// END OF TASKS =================== Have a nice day :) ===================

int main() {

    cout << "TASK 0 ========================= FMI point ============================" << endl;
    task0();

    cout << "TASK 1 ========================= f_35(x) ==============================" << endl;
    task1();

    cout << "TASK 2 ========================= Marmalade ============================" << endl;
    task2();

    cout << "TASK 3 ========================= Interesting number ===================" << endl;
    task3();

    cout << "TASK 4 ========================= Bulls & Cows =========================" << endl;
    task4();

    cout << "=================== END OF TASKS :) Have a nice day ===================" << endl;

    return 0;
}