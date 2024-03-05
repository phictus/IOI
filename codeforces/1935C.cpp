// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <limits>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;

constexpr int64_t maxn = 2000, inf = numeric_limits<int64_t>::max();
int64_t n, l, dp[maxn + 1][maxn];
Pair a[maxn];

void solveTestCase() {
    cin >> n >> l;
    for (int64_t i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a, a + n);

    for (int64_t i = 0; i < n; i++) {
        dp[1][i] = a[i].second;
    }
    for (int64_t i = 2; i <= n; i++) {
        for (int64_t j = 0; j < i - 1; j++) {
            dp[i][j] = inf;
        }

        int64_t cache = dp[i - 1][i - 2] - a[i - 2].first;
        for (int64_t j = i - 1; j < n; j++) {
            dp[i][j] = cache + a[j].first + a[j].second;
            cache = min(cache, dp[i - 1][j] - a[j].first);
        }
    }

    for (int64_t i = n; i > 0; i--) {
        int64_t minimum = inf;
        for (int64_t j = 0; j < n; j++) {
            minimum = min(minimum, dp[i][j]);
        }

        if (minimum <= l) {
            cout << i << '\n';
            return;
        }
    }
    cout << "0\n";
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
