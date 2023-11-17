// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;

constexpr int64_t maxn = 1000000;
int64_t n, d, m;
Pair a[maxn];

bool Check(int64_t k)
{
    int64_t current = 0;
    for (int64_t i = 1; i <= n; i++)
    {
        if (current >= m)
            return true;

        if (a[current].first + d < i)
            return false;

        for (int64_t j = 0; j < k && a[current].first <= i; j++)
            current++;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> d >> m;
    for (int64_t i = 0; i < m; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + m);

    int64_t l = 1, r = m;
    while (l < r)
    {
        int64_t k = (l + r) / 2;
        if (Check(k))
            r = k;
        else
            l = k + 1;
    }

    cout << l << '\n';
    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = i * l; j < min(m, (i + 1) * l); j++)
            cout << a[j].second << ' ';
        cout << "0\n";
    }

    return (0 ^ 0);
}
