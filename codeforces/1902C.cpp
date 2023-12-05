// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 200000, maxa = 1000000000;
int64_t n, k, p, a[maxn];

int64_t Gcd(int64_t x, int64_t y)
{
    if (x > y)
        swap(x, y);
    if (x == 0)
        return y;

    return Gcd(y % x, x);
}

int64_t FindK()
{
    int64_t result = 0;
    for (int64_t i = 1; i < n; i++)
        result = Gcd(result, a[i] - a[i - 1]);

    return result;
}

int64_t FindP()
{
    for (int64_t i = n - 1; i >= 1; i--)
    {
        if (a[i] - 1 != a[i - 1])
            return a[i] - 1;
    }

    return a[0] - 1;
}

int64_t SolveTestCase()
{
    cin >> n;
    for (int64_t i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] += maxa;
    }

    sort(a, a + n);
    k = FindK();
    if (k == 0)
        return 1;

    for (int64_t i = 0; i < n; i++)
        a[i] /= k;

    int64_t result = 0;
    for (int64_t i = 0; i < n; i++)
        result += a[n - 1] - a[i];

    p = FindP();
    return min(result + n, result + a[n - 1] - p);
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
