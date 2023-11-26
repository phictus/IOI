// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;

constexpr int64_t maxn = 200000;
int64_t n, x, b[maxn];
Pair a[maxn], result[maxn];

bool Solve()
{
    cin >> n >> x;
    for (int64_t i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int64_t i = 0; i < n; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    for (int64_t i = 0; i < n; i++)
        result[i].first = a[i].second;
    for (int64_t i = x; i < n; i++)
        result[i - x].second = b[i];
    for (int64_t i = 0; i < x; i++)
        result[i + n - x].second = b[i];

    int64_t count = 0;
    for (int64_t i = 0; i < n; i++)
    {
        if (a[i].first > result[i].second)
            count++;
    }

    return count == x;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
    {
        if (Solve())
        {
            cout << "YES\n";

            sort(result, result + n);
            for (int64_t i = 0; i < n; i++)
                cout << result[i].second << ' ';
            cout << '\n';
        }
        else
            cout << "NO\n";
    }

    return (0 ^ 0);
}
