// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <algorithm>
#include <limits>
#include <cstdio>
#include <cstdint>

using namespace std;

struct Minimums
{
    uint64_t Min1, Min2;
};

constexpr bool Compare1(const Minimums& v1, const Minimums& v2)
{
    return v1.Min1 < v2.Min1;
}

constexpr bool Compare2(const Minimums& v1, const Minimums& v2)
{
    return v1.Min2 < v2.Min2;
}

void UpdateMinimums(Minimums& minimums, uint64_t value)
{
    if (value <= minimums.Min1)
    {
        minimums.Min2 = minimums.Min1;
        minimums.Min1 = value;
    }
    else if (value < minimums.Min2)
        minimums.Min2 = value;
}

int main()
{
    uint64_t t;
    scanf("%llu", &t);
    while (t--)
    {
        uint64_t n;
        scanf("%llu", &n);

        Minimums minimums[n];
        for (uint64_t i = 0; i < n; i++)
        {
            minimums[i] = {numeric_limits<uint64_t>::max(), numeric_limits<uint64_t>::max()};
            uint64_t m;
            scanf("%llu", &m);
            for (uint64_t j = 0; j < m; j++)
            {
                uint64_t value;
                scanf("%llu", &value);
                UpdateMinimums(minimums[i], value);
            }
        }

        uint64_t result = 0;
        sort(minimums, minimums + n, Compare1);
        result += minimums[0].Min1;
        sort(minimums, minimums + n, Compare2);
        for (uint64_t i = 1; i < n; i++)
            result += minimums[i].Min2;

        printf("%llu\n", result);
    }

    return (0 ^ 0);
}
