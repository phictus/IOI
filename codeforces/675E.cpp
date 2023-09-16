// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cmath>

using namespace std;
using Pair = pair<int64_t, int64_t>;

constexpr int64_t maxn = 100000, maxlogn = 17;
int64_t n, a[maxn];
int64_t maxdp[maxn][maxlogn];

inline int64_t get(int64_t x, int64_t y)
{
    Pair v1, v2;
    v1.second = x;
    v1.first = a[x];
    v2.second = y;
    v2.first = a[y];

    return max(v1, v2).second;
}

void init()
{
    for (int64_t i = 0; i < n; i++)
        maxdp[i][0] = i;

    for (int64_t i = 1; i < maxlogn; i++)
    {
        for (int64_t j = 0; j + (1 << (i - 1)) < n; j++)
            maxdp[j][i] = get(maxdp[j][i - 1], maxdp[j + (1 << (i - 1))][i - 1]);
    }
}

inline int64_t maxInterval(int64_t left, int64_t right)
{
    int64_t logLength = log2f(right - left + 1);
    return get(maxdp[left][logLength], maxdp[right - (1 << logLength) + 1][logLength]);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int64_t i = 0; i < n - 1; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    a[n - 1] = n - 1;

    init();

    int64_t result = 0;
    int64_t dp[n];
    dp[n - 1] = 0;
    for (int64_t i = n - 2; i >= 0; i--)
    {
        int64_t m = maxInterval(i + 1, a[i]);
        dp[i] = dp[m] - (a[i] - m) + n - i - 1;
        result += dp[i];
    }
    cout << result << '\n';

    return (0 ^ 0);
}
