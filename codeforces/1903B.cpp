// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 1000, maxbit = 30;
int64_t n, a[maxn][maxn], b[maxn];
bool isSure[maxn];

#define GetBit(x, bit) (((x) >> (bit)) & 1)

bool MakeBit(int64_t bit)
{
    for (int64_t i = 0; i < n; i++)
        isSure[i] = false;

    int64_t sum = 0;
    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = 0; j < n; j++)
            sum += GetBit(a[i][j], bit);
    }

    if (sum == n * (n - 1))
    {
        for (int64_t i = 0; i < n; i++)
            b[i] |= (1 << bit);

        return true;
    }

    for (int64_t i = 0; i < n; i++)
    {
        sum = 0;
        for (int64_t j = 0; j < n; j++)
            sum += GetBit(a[i][j], bit);

        if (sum < n - 1)
        {
            if (isSure[i] && GetBit(b[i], bit) == 1)
                return false;
            isSure[i] = true;

            for (int64_t j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                if (GetBit(a[i][j], bit) == 0)
                {
                    if (isSure[j] && GetBit(b[j], bit) == 1)
                        return false;
                    isSure[j] = true;
                }
                else
                {
                    if (isSure[j] && GetBit(b[j], bit) == 0)
                        return false;
                    isSure[j] = true;
                    b[j] |= (1 << bit);
                }
            }
        }
    }

    return true;
}

void SolveTestCase()
{
    cin >> n;
    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = 0; j < n; j++)
            cin >> a[i][j];
    }

    for (int64_t i = 0; i < n; i++)
        b[i] = 0;
    for (int64_t i = 0; i < maxbit; i++)
    {
        if (!MakeBit(i))
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int64_t i = 0; i < n; i++)
        cout << b[i] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t testCase;
    cin >> testCase;
    while (testCase--)
        SolveTestCase();

    return (0 ^ 0);
}
