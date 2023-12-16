// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;

constexpr int64_t maxq = 300000, maxlogq = 19;
int64_t q, a[maxq], c[maxq], ancestor[maxq][maxlogq];

void AddVertex(int64_t v, int64_t p)
{
    ancestor[v][0] = p;
    for (int64_t i = 1; i < maxlogq; i++)
        ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];
}

int64_t FindNonZero(int64_t v, int64_t length = maxlogq - 1)
{
    for (int64_t i = length; i >= 0; i--)
    {
        if (a[ancestor[v][i]] != 0)
            return FindNonZero(ancestor[v][i], i - 1);
    }

    return v;
}

Pair BuyGold(int64_t v, int64_t w)
{
    Pair result = make_pair(0, 0);
    while (w > 0 && a[v] > 0)
    {
        int64_t u = FindNonZero(v);
        if (w >= a[u])
        {
            result.first += a[u];
            result.second += c[u] * a[u];

            w -= a[u];
            a[u] = 0;
        }
        else
        {
            result.first += w;
            result.second += c[u] * w;

            a[u] -= w;
            w = 0;
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> q >> a[0] >> c[0];
    for (int64_t i = 1; i <= q; i++)
    {
        int64_t type;
        cin >> type;
        if (type == 1)
        {
            int64_t p;
            cin >> p >> a[i] >> c[i];
            AddVertex(i, p);
        }
        else
        {
            int64_t v, w;
            cin >> v >> w;
            Pair result = BuyGold(v, w);
            cout << result.first << ' ' << result.second << '\n';
        }
    }

    return (0 ^ 0);
}
