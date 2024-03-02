// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;

constexpr int64_t idk = 759375, inf = numeric_limits<int64_t>::max();
int64_t dp[idk + 1];

void init() {
    dp[0] = 0;
    for (int64_t i = 1; i < idk; i++) {
        dp[i] = inf;

        if (i - 1 >= 0) {
            dp[i] = min(dp[i], dp[i - 1] + 1);
        }
        if (i - 3 >= 0) {
            dp[i] = min(dp[i], dp[i - 3] + 1);
        }
        if (i - 6 >= 0) {
            dp[i] = min(dp[i], dp[i - 6] + 1);
        }
        if (i - 10 >= 0) {
            dp[i] = min(dp[i], dp[i - 10] + 1);
        }
        if (i - 15 >= 0) {
            dp[i] = min(dp[i], dp[i - 15] + 1);
        }
    }
}

void solveTestCase() {
    int64_t n;
    cin >> n;
    cout << (idk / 15) * (n / idk) + dp[n % idk] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);

    init();
    int64_t testCase;
    cin >> testCase;
    while (testCase--) {
        solveTestCase();
    }

    return (0 ^ 0);
}
