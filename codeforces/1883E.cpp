// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100000;
int64_t n, a[maxn];
int64_t dp[maxn];

int64_t case1(int64_t id)
{
    int64_t p = a[id - 1], result = 0;
    for (int64_t i = 0; i < dp[id - 1]; i++)
    {
        p *= 2;
        if (p > a[id])
            break;

        result++;
    }

    return dp[id - 1] - result;
}

int64_t case2(int64_t id)
{
    int64_t p = a[id], result = 0;
    while (p < a[id - 1])
    {
        p *= 2;
        result++;
    }

    return dp[id - 1] + result;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int64_t i = 0; i < n; i++)
            cin >> a[i];

        dp[0] = 0;
        for (int64_t i = 1; i < n; i++)
        {
            if (a[i] >= a[i - 1])
                dp[i] = case1(i);
            else
                dp[i] = case2(i);
        }

        int64_t ans = 0;
        for (int64_t i = 0; i < n; i++)
            ans += dp[i];
        cout << ans << '\n';
    }

    return (0 ^ 0);
}
