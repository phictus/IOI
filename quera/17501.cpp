// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 1000001;
int64_t n, dp[maxn];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    int64_t result = 0, maximum = 0;
    for (int64_t i = 1; i <= n; i++) {
        int64_t a;
        cin >> a;
        maximum = max(maximum, a);
        if (maximum == i) {
            dp[++result] = i;
        }
    }

    cout << result << '\n';
    for (int64_t i = 1, j = 1; i <= result; i++) {
        cout << dp[i] - dp[i - 1] << ' ';
        while (j <= dp[i]) {
            cout << j++ << ' ';
        }
        cout << '\n';
    }

    return (0 ^ 0);
}
