// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 5000000, mod = 1000000007, p = 727;
int64_t degree[maxn];

int main()
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    degree[0] = 1;
    int64_t result = 1, pPower = 1, ph = (int64_t)s[0], rph = (int64_t)s[0];
    for (int64_t i = 1; i < s.size(); i++)
    {
        pPower = (pPower * p) % mod;

        ph = (ph + ((s[i] * pPower) % mod)) % mod;
        rph = (((p * rph) % mod) + s[i]) % mod;

        if (ph == rph)
            degree[i] = degree[(i - 1) / 2] + 1;
        result += degree[i];
    }

    cout << result << '\n';

    return (0 ^ 0);
}
