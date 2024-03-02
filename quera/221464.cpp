// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

int64_t gcd(int64_t a, int64_t b) {
    if (a > b) {
        swap(a, b);
    }
    if (a == 0) {
        return b;
    }

    return gcd(b % a, a);
}

int64_t getMin(int64_t x) {
    int64_t r = 0;
    while (x != 1) {
        if (x % 2 == 1) {
            return -1;
        }

        x /= 2;
        r++;
    }

    return r;
}

void solveTestCase() {
    int64_t n, k;
    cin >> n >> k;

    int64_t g = gcd(n, k);
    n /= g;
    k /= g;

    cout << getMin(k) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);

    int64_t testCase;
    cin >> testCase;
    while (testCase--) {
        solveTestCase();
    }

    return (0 ^ 0);
}
