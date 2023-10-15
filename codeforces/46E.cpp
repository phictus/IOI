// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 1500, neginf = numeric_limits<int64_t>::min();
int64_t n, m;
int64_t table[maxn][maxn];
int64_t sum[maxn][maxn];
int64_t dp[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = 0; j < m; j++)
            cin >> table[i][j];
    }

    for (int64_t i = 0; i < n; i++)
    {
        sum[i][0] = table[i][0];
        for (int64_t j = 1; j < m; j++)
            sum[i][j] = sum[i][j - 1] + table[i][j];
    }

    for (int64_t i = 0; i < m; i++)
        dp[0][i] = sum[0][i];
    for (int64_t i = 1; i < n; i++)
    {
        int64_t maxCache = neginf;
        int64_t begin, end, delta;
        if (i % 2 == 0)
        {
            begin = 1;
            end = m;
            delta = 1;

            dp[i][0] = neginf;
        }
        else
        {
            begin = m - 2;
            end = -1;
            delta = -1;

            dp[i][m - 1] = neginf;
        }

        for (int64_t j = begin; delta * j < delta * end; j += delta)
        {
            maxCache = max(maxCache, dp[i - 1][j - delta]);
            dp[i][j] = sum[i][j] + maxCache;
        }
    }

    int64_t ans = neginf;
    for (int64_t i = 0; i < m; i++)
        ans = max(ans, dp[n - 1][i]);
    cout << ans << '\n';

    return (0 ^ 0);
}
