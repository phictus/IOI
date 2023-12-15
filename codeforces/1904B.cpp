// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <limits>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;

constexpr int64_t maxn = 100000, inf = numeric_limits<int64_t>::max();
int64_t n, ps[maxn], result[maxn];
Pair a[maxn + 1];

void SolveTestCase()
{
    cin >> n;
    for (int64_t i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    a[n].first = inf;
    sort(a, a + n);

    ps[0] = a[0].first;
    for (int64_t i = 1; i < n; i++)
        ps[i] = ps[i - 1] + a[i].first;

    int64_t last;
    for (int64_t i = n - 1; i >= 0; i--)
    {
        if (ps[i] < a[i + 1].first)
            last = i;

        result[a[i].second] = last;
    }

    for (int64_t i = 0; i < n; i++)
        cout << result[i] << ' ';
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
