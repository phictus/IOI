// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 200000;
int64_t n, a[maxn], dp[maxn];

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

        dp[0] = a[0];
        for (int64_t i = 1; i < n; i++)
        {
            dp[i] = a[i];
            if (abs(a[i]) % 2 != abs(a[i - 1]) % 2)
                dp[i] = max(dp[i], dp[i - 1] + a[i]);
        }

        int64_t ans = dp[0];
        for (int64_t i = 1; i < n; i++)
            ans = max(ans, dp[i]);
        cout << ans << '\n';
    }

    return (0 ^ 0);
}
