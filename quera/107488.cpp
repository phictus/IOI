// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <limits>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 1000000, neginf = numeric_limits<int64_t>::min();
int64_t n, a[maxn], dp[maxn], pMaxDp[maxn];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int64_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    dp[0] = a[0] == 1 ? 1 : neginf;
    pMaxDp[0] = 0;
    for (int64_t i = 1; i < n; i++) {
        pMaxDp[i] = max(pMaxDp[i - 1], dp[i - 1]);
        if (a[i] > i + 1) {
            dp[i] = neginf;
        } else {
            dp[i] = pMaxDp[i - a[i] + 1] + 1;
        }
    }
    cout << dp[n - 1] << '\n';

    return (0 ^ 0);
}
