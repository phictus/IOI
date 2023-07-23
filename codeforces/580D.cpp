// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdio>
#include <cstdint>
#include <algorithm>

using namespace std;

constexpr uint64_t maxn = 19;
uint64_t n, m, k;
uint64_t satisfaction[maxn];
uint64_t rule[maxn * maxn];
uint64_t dp[maxn * (1 << (maxn - 1))];

constexpr uint64_t at(uint64_t x, uint64_t y)
{
    return x + y * maxn;
}

uint64_t BestSatisfaction()
{
    uint64_t result = 0;
    if (m == 1)
    {
        for (uint64_t i = 1; i <= n; i++)
            result = max(result, satisfaction[i]);

        return result;
    }

    for (uint64_t i = 2; i < (1 << n); i++)
    {
        for (uint64_t j = 1; j <= n; j++)
        {
            if (dp[at(j, i)] == 0 && (i >> (j - 1)) & 1)
            {
                uint64_t x = 1;
                const uint64_t y = i & ~(1 << (j - 1));

                for (uint64_t k = 1; k <= n; k++)
                {
                    if ((y >> (k - 1)) & 1)
                    {
                        dp[at(j, i)] = max(dp[at(j, i)], dp[at(k, y)] + rule[at(k, j)] + satisfaction[j]);
                        x++;
                    }
                }

                if (x == m)
                    result = max(result, dp[at(j, i)]);
            }
        }
    }

    return result;
}

int main()
{
    scanf("%llu%llu%llu", &n, &m, &k);
    for (uint64_t i = 1; i <= n; i++)
    {
        scanf("%llu", &satisfaction[i]);
        dp[at(i, 1 << (i - 1))] = satisfaction[i];
    }
    for (uint64_t i = 1; i <= k; i++)
    {
        uint64_t x, y, z;
        scanf("%llu%llu%llu", &x, &y, &z);
        rule[at(x, y)] = z;
    }

    printf("%llu\n", BestSatisfaction());

    return (0 ^ 0);
}
