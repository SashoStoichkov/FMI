#include <iostream>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <limits>

using namespace std;

int digitCount(int number) {
    int count = 0;

    while (number > 0) {
        count++;
        number /= 10;
    }

    return count;
}

bool check(int N, int K) {
    int n = N;
    int k = K;

    int digitCountN = digitCount(N);
    int digitCountK = digitCount(K);

    int digitK, digitN, index = 0;

    while (k > 0) {
        digitK = k % 10;
        digitN = n % 10;

        while (digitK != digitN && n > 0) {
            n /= 10;
            index++;

            digitN = n % 10;
        }

        if (n == 0) {
            // no match
            return false;
        } else if (index == 0) {
            // no B
            return false;
        } else {
            k /= 10;
        }
    }

    return (index < digitCountN - 1);
}

bool result(int N, int K) {
    if (N > 0 && K > 0) {
        if (N > K) {
            return check(N, K);
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main() {

    int N, K;
    cin >> N >> K;

    cout << boolalpha << result(N, K) << endl;

    return 0;
}