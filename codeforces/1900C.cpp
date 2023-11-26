// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <limits>
#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 300000;
int64_t n, l[maxn + 1], r[maxn + 1], result;
char c[maxn + 1];

void DoDfs(int64_t v, int64_t count)
{
    if (l[v] == 0 && r[v] == 0)
    {
        result = min(result, count);
        return;
    }

    int64_t lCount = count, rCount = count;
    if (c[v] != 'L')
        lCount++;
    if (c[v] != 'R')
        rCount++;

    if (l[v] != 0)
        DoDfs(l[v], lCount);
    if (r[v] != 0)
        DoDfs(r[v], rCount);
}

void Solve()
{
    cin >> n;
    for (int64_t i = 1; i <= n; i++)
        cin >> c[i];
    for (int64_t i = 1; i <= n; i++)
        cin >> l[i] >> r[i];

    result = numeric_limits<int64_t>::max();
    DoDfs(1, 0);
    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
        Solve();

    return (0 ^ 0);
}
