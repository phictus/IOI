// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>

using namespace std;

constexpr int64_t maxn = 101;
int64_t n, d, a[maxn], x[maxn], y[maxn], minCost[maxn][maxn];

#define COST(v, u) (d * (abs(x[v] - x[u]) + abs(y[v] - y[u])))

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> d;

    for (int64_t i = 2; i < n; i++)
        cin >> a[i];
    a[0] = 0;
    a[n] = 0;

    for (int64_t i = 1; i <= n; i++)
        cin >> x[i] >> y[i];

    for (int64_t i = 1; i <= n; i++)
    {
        for (int64_t j = 1; j <= n; j++)
        {
            if (i == j)
                minCost[i][j] = 0;
            else
                minCost[i][j] = COST(i, j) - a[j];
        }
    }

    for (int64_t mid = 1; mid <= n; mid++)
    {
        for (int64_t i = 1; i <= n; i++)
        {
            for (int64_t j = 1; j <= n; j++)
                minCost[i][j] = min(minCost[i][j], minCost[i][mid] + minCost[mid][j]);
        }
    }

    cout << minCost[1][n] << '\n';

    return (0 ^ 0);
}
