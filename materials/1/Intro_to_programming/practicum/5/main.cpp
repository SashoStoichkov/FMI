#include <iostream>
#include <cmath>
using namespace std;

// https://bit.ly/8nov2021

void zad1() {
    int n;
    cin >> n;

    // convert to binary
    int binary = 0;
    int power = 1;
    while (n > 0) {
        int digit = n % 2;
        binary += digit * power;
        power *= 10;
        n /= 2;
    }

    cout << "Binary: " << binary << endl;

    // how many 1s
    int ones = 0;
    while (binary > 0) {
        if (binary % 10 == 1) {
            ones++;
        }
        binary /= 10;
    }

    cout << "Ones: " << ones << endl;
}

void zad2() {
    int n;
    cin >> n;

    // print triangle
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "#";
        }
        cout << endl;
    }
}

bool isPrime(int n) {
    if (n == 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void zad3() {
    int p, q;
    cin >> p >> q;

    cout << "Result:" << endl;

    for (int i = p; i <= q; i++) {
        for (int j = i+4; j <= q; j+=4) {
            if (isPrime(i) && isPrime(j) && i + 4 == j) {
                cout << i << " " << j << endl;
            }
        }
    }
}

void zad4() {
    int p, q;
    cin >> p >> q;

    int sum = 0;

    for (int i = p; i <= q; i++) {
        int digitSum = 0;
        int num = i;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }

        if (digitSum % 3 == 0 && digitSum % 2 == 0) {
            cout << i << endl;
            sum += i;
        }
    }

    cout << "Sum: " << sum << endl;
}

void zad5() {
    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Result: ";

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] % 3 == 0) {
            cout << nums[i] << " ";
            count++;
        }
    }

    cout << endl << "Count: " << count << endl;
}

void zad6() {
    int n;
    cin >> n;

    double nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = n-1; i >= 0; i--) {
        cout << nums[i] << " ";
    }

    cout << endl;
}

void zad7() {
    int n;
    cin >> n;

    double nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // max and min
    double max = nums[0];
    double min = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] > max) { max = nums[i]; }
        if (nums[i] < min) { min = nums[i]; }
    }

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
}

void zad8() {
    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Result: ";

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(nums[i])) {
            cout << nums[i] << " ";
            count++;
        }
    }

    cout << endl << "Count: " << count << endl;
}

void zad9() {
    int n, m;
    cin >> n >> m;

    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int nums2[m];
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    cout << "Result: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (nums[i] == nums2[j]) {
                cout << nums[i] << " ";
            }
        }
    }

    cout << endl;
}

void zad10() {
    int n;
    cin >> n;

    double times[n];
    for (int i = 0; i < n; i++) {
        cin >> times[i];
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

    return 0;
}