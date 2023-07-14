// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <limits>

using namespace std;

constexpr int32_t maxn = 100000;
int32_t n;
int32_t numbers[maxn];
int32_t dp[maxn * 32];
#define AT(x, y) (x) + ((y) * maxn)

void Initialize()
{
    for (uint32_t i = 0; i < n; i++)
        dp[AT(i, 0)] = numbers[i];

    for (int32_t i = n - 1; i >= 0; i--)
        for (int32_t j = 1; i + (1 << j) <= n; j++)
            dp[AT(i, j)] = min(dp[AT(i, j - 1)], dp[AT(i + (1 << (j - 1)), (j - 1))]);
}

int32_t MostSignificantBit(uint32_t n)
{
    int32_t result = -1;
    while (n != 0)
    {
        n /= 2;
        result++;
    }

    return result;
}

int32_t RangeMinimumQuery(int32_t l, int32_t r)
{
    if (l > r)
        return numeric_limits<int32_t>::max();
    else
    {
        const int32_t msb = MostSignificantBit(r - l + 1);
        return min(dp[AT(l, msb)], RangeMinimumQuery(l + (1 << msb), r));
    }
}

int main()
{
    scanf("%d", &n);
    for (int32_t i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    Initialize();

    int32_t q;
    scanf("%d", &q);
    while (q--)
    {
        int32_t l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", RangeMinimumQuery(l, r));
    }

    return (0 ^ 0);
}
