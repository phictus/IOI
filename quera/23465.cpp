// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100000;
int64_t n, m, dp[maxn + 1];

struct Interval {
    int64_t l, r;
    bool operator<(const Interval& other) const {
        if (l == other.l) {
            return r > other.r;
        }
        return l < other.l;
    }
} a[maxn];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int64_t i = 0; i < m; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].l--;
        a[i].r--;
    }
    sort(a, a + m);

    dp[0] = -1;
    for (int64_t i = 1; i <= m; i++) {
        dp[i] = max(dp[i - 1], a[i - 1].r);
    }

    int64_t result = 0, index = 0;
    for (int64_t i = 0; i < n; i++) {
        while (index != m && a[index].l <= i) {
            index++;
        }

        if (dp[index] >= i) {
            i = dp[index];
        }
        result++;
    }

    cout << result << '\n';

    return (0 ^ 0);
}
