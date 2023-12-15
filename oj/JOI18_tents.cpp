// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 3000, mod = 1000000007;
int64_t n, m, dp[maxn + 1][maxn + 1];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int64_t i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int64_t j = 0; j <= m; j++)
        dp[0][j] = 1;
    for (int64_t i = 1; i <= n; i++)
        dp[i][1] = 1 + 4 * i + (i * (i - 1)) / 2;
    for (int64_t j = 1; j <= m; j++)
        dp[1][j] = 1 + 4 * j + (j * (j - 1)) / 2;

    for (int64_t i = 2; i <= n; i++)
    {
        for (int64_t j = 2; j <= m; j++)
        {
            dp[i][j] = dp[i][j - 1] + 4 * i * dp[i - 1][j - 1] + i * (j - 1) * dp[i - 1][j - 2] + (i * (i - 1) / 2) * dp[i - 2][j - 1];
            dp[i][j] %= mod;
        }
    }

    cout << dp[n][m] - 1 << '\n';

    return (0 ^ 0);
}
