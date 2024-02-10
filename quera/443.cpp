// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;
using PriorityQueue = priority_queue<Pair, vector<Pair>, greater<Pair>>;

constexpr int64_t maxn = 50001, inf = numeric_limits<int64_t>::max();
int64_t n, m, t, k, cityCount, d[maxn];
vector<Pair> adj[maxn];

void RemoveCities(int64_t source)
{
    if (d[source] >= k)
        cityCount--;
    d[source] = 0;

    PriorityQueue q;
    q.push(make_pair(0, source));

    while (!q.empty())
    {
        auto[dist, v] = q.top();
        q.pop();

        if (dist != d[v] || dist >= k)
            continue;

        for (auto[w, u] : adj[v])
        {
            if (d[u] > dist + w && dist + w < k)
            {
                if (d[u] >= k)
                    cityCount--;
                d[u] = dist + w;

                q.push(make_pair(d[u], u));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> t >> k;
    for (int64_t i = 0; i < m; i++)
    {
        int64_t v, u, w;
        cin >> v >> u >> w;
        adj[v].push_back(make_pair(w, u));
        adj[u].push_back(make_pair(w, v));
    }

    cityCount = n;
    fill(d, d + maxn, inf);

    for (int64_t i = 0; i < t; i++)
    {
        int64_t a;
        cin >> a;
        RemoveCities(a);
        cout << cityCount << '\n';
    }

    return (0 ^ 0);
}
