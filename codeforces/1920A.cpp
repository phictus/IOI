// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100, inf = numeric_limits<int64_t>::max();
int64_t a[maxn];

int64_t SolveTestCase()
{
    int64_t n, c1 = 0, c2 = inf;
    cin >> n;
    for (int64_t i = 0; i < n; i++)
        a[i] = 0;
    for (int64_t i = 0; i < n; i++)
    {
        int64_t type, x;
        cin >> type >> x;
        if (type == 1)
            c1 = max(c1, x);
        else if (type == 2)
            c2 = min(c2, x);
        else
            a[i] = x;
    }

    if (c1 > c2)
        return 0;

    int64_t cnt = 0;
    for (int64_t i = 0; i < n; i++)
        cnt += c1 <= a[i] && a[i] <= c2;
    return c2 - c1 + 1 - cnt;
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
