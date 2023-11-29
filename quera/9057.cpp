// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100000, maxk = 250;
int64_t n, q, a[maxn], dp[maxn][maxk];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];

    for (int64_t j = 1; j < maxk; j++)
    {
        for (int64_t i = n - 1; i >= 0; i--)
        {
            if (i + j >= n)
                dp[i][j] = a[i];
            else
                dp[i][j] = a[i] + dp[i + j][j];
        }
    }

    cin >> q;
    while (q--)
    {
        int64_t s, k;
        cin >> s >> k;
        s--;

        if (k < maxk)
            cout << dp[s][k] << '\n';
        else
        {
            int64_t result = 0;
            for (int64_t i = s; i < n; i += k)
                result += a[i];
            cout << result << '\n';
        }
    }

    return (0 ^ 0);
}
