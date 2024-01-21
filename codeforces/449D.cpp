// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 1000001, maxloga = 20, mod = 1000000007;
int64_t dp[1 << maxloga], power2[maxn];

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t n;
    cin >> n;
    for (int64_t i = 0; i < n; i++)
    {
        int64_t a;
        cin >> a;
        dp[a]++;
    }

    power2[0] = 1;
    for (int64_t i = 1; i < maxn; i++)
        power2[i] = (2 * power2[i - 1]) % mod;

    for (int64_t i = 0; i < maxloga; i++)
    {
        for (int64_t mask = 0; mask < (1 << maxloga); mask++)
        {
            if (((mask >> i) & 1) == 0)
                dp[mask] += dp[mask ^ (1 << i)];
        }
    }

    int64_t result = 0;
    for (int64_t mask = 0; mask < (1 << maxloga); mask++)
    {
        if (__builtin_parity(mask))
            result -= power2[dp[mask]] - 1;
        else
            result += power2[dp[mask]] - 1;

        result = (result + mod) % mod;
    }
    cout << result << '\n';

    return (0 ^ 0);
}
