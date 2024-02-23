// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <bitset>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100000;
int64_t n, a[2 * maxn], prefixSum[2 * maxn];
bitset<2 * maxn> dp;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int64_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    prefixSum[0] = a[0];
    for (int64_t i = 1; i < 2 * n; i++) {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }

    dp[0] = 1;
    for (int64_t i = 0; i < 2 * n; i++) {
        dp |= (dp >> i) << (a[i] + i);
    }

    int64_t result = 0;
    for (int64_t i = 0; i < 2 * n; i++) {
        result = max(result, prefixSum[i] * dp[i] - i);
    }
    cout << result << '\n';

    return (0 ^ 0);
}
