// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 301, neginf = numeric_limits<int64_t>::min();
int64_t n;
int64_t grid[maxn][maxn];
int64_t dp[maxn][maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int64_t i = 1; i <= n; i++)
    {
        for (int64_t j = 1; j <= n; j++)
            cin >> grid[i][j];
    }

    for (int64_t i = 0; i <= n; i++)
    {
        for (int64_t j = 0; j <= n; j++)
        {
            for (int64_t k = 0; k <= n; k++)
                dp[i][j][k] = neginf;
        }
    }
    dp[0][1][0] = 0;

    for (int64_t x1 = 1; x1 <= n; x1++)
    {
        for (int64_t y1 = 1; y1 <= n; y1++)
        {
            const int64_t begin = max(x1 + y1 - n, (int64_t)1);
            const int64_t end = min(x1 + y1, n + 1);

            for (int64_t x2 = begin; x2 < end; x2++)
            {
                const int64_t dx1[] = { 1, 1, 0, 0 };
                const int64_t dy1[] = { 0, 0, 1, 1 };
                const int64_t dx2[] = { 0, 1, 0, 1 };
                for (int64_t i = 0; i < 4; i++)
                    dp[x1][y1][x2] = max(dp[x1][y1][x2], dp[x1 - dx1[i]][y1 - dy1[i]][x2 - dx2[i]]);

                const int64_t y2 = (x1 + y1) - x2;
                if (x1 == x2 && y1 == y2)
                    dp[x1][y1][x2] += grid[x1][y1];
                else
                    dp[x1][y1][x2] += grid[x1][y1] + grid[x2][y2];
            }
        }
    }

    cout << dp[n][n][n] << '\n';

    return (0 ^ 0);
}
