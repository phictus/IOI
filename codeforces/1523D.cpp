// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <random>
#include <vector>
#include <cstdint>
#include <cstring>

using namespace std;

constexpr int64_t maxn = 200000, maxp = 15, tryCount = 25;
int64_t n, m, p, a[maxn], supersetCount[1LL << maxp];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> p;
    for (int64_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int64_t j = 0; j < m; j++)
        {
            if (s[j] == '1')
                    a[i] |= 1LL << j;
        }
    }

    auto rng = default_random_engine(random_device()());
    auto rngDistribution = uniform_int_distribution<int64_t>(0, n - 1);

    int64_t bestResult = 0;
    for (int64_t t = 0; t < tryCount; t++)
    {
        int64_t x = rngDistribution(rng);
        vector<int64_t> likedList;
        for (int64_t i = 0; i < m; i++)
        {
            if (a[x] & (1LL << i))
                likedList.push_back(i);
        }

        for (int64_t i = 0; i < n; i++)
        {
            int64_t reducedMask = 0;
            for (int64_t j = 0; j < likedList.size(); j++)
            {
                if (a[i] & (1LL << likedList[j]))
                    reducedMask |= 1LL << j;
            }

            supersetCount[reducedMask]++;
        }

        for (int64_t i = 0; i < maxp; i++)
        {
            for (int64_t mask = 0; mask < (1 << maxp); mask++)
            {
                if ((mask & (1LL << i)) == 0)
                    supersetCount[mask] += supersetCount[mask | (1LL << i)];
            }
        }

        int64_t reducedResult = 0;
        for (int64_t mask = 0; mask < (1 << maxp); mask++)
        {
            if (supersetCount[mask] >= (n + 1) / 2 &&
                __builtin_popcount(mask) > __builtin_popcount(reducedResult))
                reducedResult = mask;
        }


        if (__builtin_popcount(reducedResult) > __builtin_popcount(bestResult))
        {
            int64_t result = 0;
            for (int64_t i = 0; i < likedList.size(); i++)
            {
                if ((reducedResult & (1LL << i)) != 0)
                    result |= (1LL << likedList[i]);
            }

            bestResult = result;
        }

        memset(supersetCount, 0, (1LL << maxp) * sizeof(int64_t));
    }

    string ans = string(m, '0');
    for (int64_t i = 0; i < m; i++)
    {
        if ((bestResult & (1LL << i)) != 0)
            ans[i] = '1';
    }
    cout << ans << '\n';

    return (0 ^ 0);
}
