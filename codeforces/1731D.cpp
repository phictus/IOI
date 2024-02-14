// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <limits>
#include <cstdint>
#include <cmath>

using namespace std;

constexpr int64_t maxnm = 1000000, maxlogmn = 20, inf = numeric_limits<int64_t>::max();
int64_t n, m, st[maxnm][maxlogmn];

#define AT(i, j) (((i) * m) + (j))

void InitSt()
{
    for (int64_t k = 1; k < maxlogmn; k++)
    {
        for (int64_t i = 0; i + (1 << k) <= n; i++)
        {
            for (int64_t j = 0; j + (1 << k) <= m; j++)
            {
                st[AT(i, j)][k] =
                    min(st[AT(i, j)][k - 1],
                    min(st[AT(i + (1 << (k - 1)), j)][k - 1],
                    min(st[AT(i, j + (1 << (k - 1)))][k - 1],
                        st[AT(i + (1 << (k - 1)), j + (1 << (k - 1)))][k - 1])));
            }
        }
    }
}

int64_t GetMin(int64_t x, int64_t y, int64_t l)
{
    int64_t logl = log2(l);
    int64_t diff = l - (1 << logl);

    return
        min(st[AT(x, y)][logl],
        min(st[AT(x + diff, y)][logl],
        min(st[AT(x, y + diff)][logl],
            st[AT(x + diff, y + diff)][logl])));
}

bool Check(int64_t l)
{
    for (int64_t i = 0; i + l <= n; i++)
    {
        for (int64_t j = 0; j + l <= m; j++)
        {
            if (GetMin(i, j, l) >= l)
                return true;
        }
    }

    return false;
}

int64_t SolveTestCase()
{
    cin >> n >> m;
    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = 0; j < m; j++)
            cin >> st[AT(i, j)][0];
    }
    InitSt();

    int64_t l = 1, r = min(n, m) + 1;
    while (l + 1 != r)
    {
        int64_t mid = (l + r) / 2;
        if (Check(mid))
            l = mid;
        else
            r = mid;
    }

    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t testCase;
    cin >> testCase;
    while (testCase--)
        cout << SolveTestCase() << '\n';

    return (0 ^ 0);
}
