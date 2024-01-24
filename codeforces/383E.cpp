// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 10000, maxlogq = 24;
int64_t n, a[maxn], dp[1 << maxlogq];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = 0; j < 3; j++)
        {
            char c;
            cin >> c;
            a[i] |= 1 << (c - 'a');
        }

        dp[a[i]]++;
    }

    for (int64_t i = 0; i < maxlogq; i++)
    {
        for (int64_t mask = (1 << maxlogq) - 1; mask >= 0; mask--)
        {
            if (((mask >> i) & 1) == 1)
                dp[mask] += dp[mask - (1 << i)];
        }
    }

    int64_t result = 0;
    for (int64_t mask = 0; mask < (1 << maxlogq); mask++)
        result ^= (n - dp[mask]) * (n - dp[mask]);
    cout << result << '\n';

    return (0 ^ 0);
}
