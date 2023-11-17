// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
#include <cstdint>

using namespace std;
using Vec = vector<int64_t>;

constexpr int64_t maxn = 100000, inf = numeric_limits<int64_t>::max();
int64_t n, q, p[maxn], dp[maxn], vertexId[maxn], startTime[maxn + 1], finishTime[maxn + 1];
Vec adj[maxn + 1];
Vec* tree;

int64_t discoveryTime = 0;
void InitDiscovery(int64_t v = 1, int64_t p = 1)
{
    vertexId[discoveryTime] = v;
    startTime[v] = discoveryTime;
    discoveryTime++;

    for (int64_t u : adj[v])
    {
        if (u != p)
            InitDiscovery(u, v);
    }

    finishTime[v] = discoveryTime;
}

void InitDp()
{
    auto v = Vec(n + 1);
    for (int64_t i = 0; i < n; i++)
        v[p[i]] = i;

    for (int64_t i = 0; i < n; i++)
        dp[i] = v[vertexId[i]];
}

void Merge(const Vec& src1, const Vec& src2, Vec& dst)
{
    dst.reserve(src1.size() + src2.size());

    auto it1 = src1.begin(), it2 = src2.begin();
    while (it1 != src1.end() || it2 != src2.end())
    {
        if (it1 == src1.end() || (it2 != src2.end() && *it2 < *it1))
        {
            dst.push_back(*it2);
            it2++;
        }
        else
        {
            dst.push_back(*it1);
            it1++;
        }
    }
}

void Build(int64_t idl = 0, int64_t idr = n, int64_t id = 1)
{
    if (idl + 1 == idr)
    {
        tree[id].push_back(dp[idl]);
        return;
    }

    int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
    Build(idl, mid, lc);
    Build(mid, idr, rc);

    Merge(tree[lc], tree[rc], tree[id]);
}

int64_t Get(int64_t l, int64_t r, int64_t value, int64_t idl = 0, int64_t idr = n, int64_t id = 1)
{
    if (l >= idr || r <= idl)
        return inf;
    if (l <= idl && r >= idr)
    {
        auto it = lower_bound(tree[id].begin(), tree[id].end(), value);
        if (it == tree[id].end())
            return inf;
        else
            return *it;
    }

    int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
    return min(Get(l, r, value, idl, mid, lc), Get(l, r, value, mid, idr, rc));
}

void Solve()
{
    cin >> n >> q;
    for (int64_t i = 1; i < n; i++)
    {
        int64_t v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for (int64_t i = 0; i < n; i++)
        cin >> p[i];

    InitDiscovery();
    for (int64_t i = 1; i <= n; i++)
        adj[i].clear();
    discoveryTime = 0;

    InitDp();

    tree = new Vec[4 * n];
    Build();

    while (q--)
    {
        int64_t l, r, v;
        cin >> l >> r >> v;

        if (Get(startTime[v], finishTime[v], l - 1) < r)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    delete[] tree;
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
