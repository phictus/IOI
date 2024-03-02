// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100;
int64_t n, a[maxn];

void solveTestCase() {
    cin >> n;
    for (int64_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    cout << a[n - 1] - a[0] + a[n - 2] - a[0] + a[n - 2] - a[1] + a[n - 1] - a[1] << '\n';
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
