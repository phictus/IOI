// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>

using namespace std;

constexpr int32_t maxn = 501;

int main()
{
    ios_base::sync_with_stdio(false);

    int32_t n;
    cin >> n;
    int32_t color[n];
    for (int32_t i = 0; i < n; i++)
        cin >> color[i];

    int32_t minMoves[maxn][maxn];
    for (int32_t i = 0; i < maxn; i++)
        for (int32_t j = 0; j < maxn; j++)
            minMoves[i][j] = 0;

    for (int32_t i = 0; i < n; i++)
        minMoves[i][i] = 1;
    for (int32_t i = 1; i < n; i++)
    {
        for (int32_t j = i - 1; j >= 0; j--)
        {
            minMoves[j][i] = minMoves[j + 1][i] + 1;

            if (color[j] == color[j + 1])
                minMoves[j][i] = min(minMoves[j][i], minMoves[j + 2][i] + 1);

            for (int32_t k = j + 2; k <= i; k++)
            {
                if (color[k] == color[j])
                    minMoves[j][i] = min(minMoves[j][i], minMoves[j + 1][k - 1] + minMoves[k + 1][i]);
            }
        }
    }

    cout << minMoves[0][n - 1] << '\n';

    return (0 ^ 0);
}
