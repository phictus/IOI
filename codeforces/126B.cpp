// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 1000000, prime = 727, mod = 1000000009;
int64_t n, primePower[maxn], sHash[maxn];

int64_t GetHash(int64_t l, int64_t r)
{
    if (r >= n - 1)
        return sHash[l];
    return ((sHash[l] + mod) - (primePower[r - l + 1] * sHash[r + 1]) % mod) % mod;
}

bool Check(int64_t x)
{
    for (int64_t i = 1; x + i < n - 1; i++)
    {
        if (GetHash(0, x) == GetHash(i, x + i))
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    n = s.size();

    primePower[0] = 1;
    for (int64_t i = 1; i < n; i++)
        primePower[i] = (primePower[i - 1] * prime) % mod;

    sHash[n - 1] = s[n - 1];
    for (int64_t i = n - 2; i >= 0; i--)
        sHash[i] = (((prime * sHash[i + 1]) % mod) + s[i]) % mod;

    vector<int64_t> v;
    for (int64_t i = 0; i < n - 1; i++)
    {
        if (GetHash(0, i) == GetHash(n - i - 1, n - 1))
            v.push_back(i);
    }

    if (v.empty() || !Check(v.front()))
    {
        cout << "Just a legend\n";
        return (0 ^ 0);
    }


    int64_t l = 0, r = v.size();
    while (l + 1 != r)
    {
        int64_t mid = (l + r) / 2;
        if (Check(v[mid]))
            l = mid;
        else
            r = mid;
    }

    for (int64_t i = 0; i <= v[l]; i++)
        cout << s[i];
    cout << '\n';

    return (0 ^ 0);
}
