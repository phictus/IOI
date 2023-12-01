// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

constexpr int64_t maxa = 5000000;
bool isComposite[maxa + 1];
vector<int64_t> pListMod[4];

constexpr int64_t maxn = 200000;
int64_t n, a[maxn], dp[maxn];

void InitPrime()
{
    for (int64_t i = 2; i * i <= maxa; i++)
    {
        if (!isComposite[i])
        {
            for (int64_t j = i * i; j <= maxa; j += i)
                isComposite[j] = true;
        }
    }

    pListMod[1].push_back(1);
    for (int64_t i = 2; i <= maxa; i++)
    {
        if (!isComposite[i])
            pListMod[i % 4].push_back(i);
    }
}

int64_t FindMax(int64_t x)
{
    int64_t l = 0, r = pListMod[x % 4].size();
    while (l + 1 != r)
    {
        int64_t mid = (l + r) / 2;
        if (pListMod[x % 4][mid] < x)
            l = mid;
        else if (pListMod[x % 4][mid] > x)
            r = mid;
        else
            return pListMod[x % 4][mid];
    }

    return pListMod[x % 4][l];
}

bool SolveTestCase()
{
    cin >> n;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];

    for (int64_t i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            dp[i] = a[i] / 2;
        else
            dp[i] = ((a[i] - FindMax(a[i])) / 2) + 1;
    }

    int64_t minimum = 0; 
    for (int64_t i = 1; i < n; i++)
    {
        if (dp[minimum] > dp[i])
            minimum = i;
    }

    if (a[minimum] % 4 != 0)
        return true;
    else
    {
        for (int64_t i = 1; i < n; i++)
        {
            int64_t index = (minimum + i) % n;
            if (a[index] % 4 == 0)
                continue;

            if (index > minimum)
            {
                if (0 >= dp[index] - dp[minimum])
                    return true;
            }
            else
            {
                if (2 >= dp[index] - dp[minimum])
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    InitPrime();

    int64_t testCase;
    cin >> testCase;
    while (testCase--)
    {
        if (SolveTestCase())
            cout << "Farmer John\n";
        else
            cout << "Farmer Nhoj\n";
    }

    return (0 ^ 0);
}
