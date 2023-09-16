// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

constexpr int64_t maxn = 500001, maxlogn = 20;
int64_t n, m, a, k = 0;
map<int64_t, int64_t> lastTime;
int64_t virtualLeft[maxn], virtualRight[maxn];
int64_t dp[maxn][maxlogn];

void init()
{
    for (int64_t i = 1; i <= k; i++)
        dp[i][0] = virtualRight[i] - virtualLeft[i];

    for (int64_t i = 1; i < maxlogn; i++)
    {
        for (int64_t j = 1; j + ((1 << (i - 1))) <= n; j++)
        {
            const int64_t jPrime = j + (1 << (i - 1));
            dp[j][i] = min(dp[j][i - 1], dp[jPrime][i - 1]);
        }
    }
}

int64_t get(int64_t l, int64_t r)
{
    if (l > r)
        return -1;

    const int64_t logLength = log2(r - l + 1);
    const int64_t lPrime = r - (1 << logLength) + 1; 

    return min(dp[l][logLength], dp[lPrime][logLength]);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    fill(virtualLeft, virtualLeft + n + 1, 0);
    fill(virtualRight, virtualRight + n + 1, 0);

    for (int64_t i = 1; i <= n; i++)
    {
        cin >> a;

        if (lastTime[a] != 0 && lastTime[a] > virtualLeft[k])
        {
            k++;
            virtualLeft[k] = lastTime[a];
            virtualRight[k] = i;
        }

        lastTime[a] = i;
    }

    init();

    while (m--)
    {
        int64_t l, r;
        cin >> l >> r;

        const int64_t virtualL = lower_bound(virtualLeft + 1, virtualLeft + k + 1, l) - virtualLeft;
        const int64_t virtualR = upper_bound(virtualRight + 1, virtualRight + k + 1, r) - virtualRight - 1;

        cout << get(virtualL, virtualR) << '\n';
    }

    return (0 ^ 0);
}
