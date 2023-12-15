// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 2000;
int64_t n, k, a[maxn];

int64_t Get(int64_t x)
{
    int64_t l = 0, r = n - 2;
    while (l < r)
    {
        int64_t mid = (l + r) / 2;

        if (x >= a[mid] && x <= a[mid + 1])
            return mid;

        if (x < a[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }

    return l;
}

int64_t SolveTestCase()
{
    cin >> n >> k;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    if (k >= 3)
        return 0;
    if (k == 1)
    {
        int64_t result = a[0];
        for (int64_t i = 1; i < n; i++)
            result = min(result, a[i] - a[i - 1]);

        return result;
    }

    int64_t result = a[0];
    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = i + 1; j < n; j++)
        {
            int64_t x = a[j] - a[i];
            result = min(result, x);

            int64_t v = Get(x);
            result = min(result, abs(x - a[v]));
            result = min(result, a[v + 1] - x);
        }
    }

    return result;
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
