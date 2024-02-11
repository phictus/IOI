// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;
using PriorityQueue = priority_queue<Pair, vector<Pair>, greater<Pair>>;

constexpr int64_t maxn = 100001, inf = numeric_limits<int64_t>::max();
int64_t n, m;
vector<Pair> adj[maxn];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int64_t i = 0; i < m; i++)
    {
        int64_t v, u, w;
        cin >> v >> u >> w;
        adj[v].push_back(make_pair(w, u));
        adj[u].push_back(make_pair(w, v));
    }

    PriorityQueue q;
    auto d = vector<int64_t>(maxn, inf);
    auto p = vector<int64_t>(maxn, -1);

    q.push(make_pair(0, 1));
    d[1] = 0;

    while (!q.empty())
    {
        auto[dist, v] = q.top();
        q.pop();

        if (dist != d[v])
            continue;

        for (auto[w, u] : adj[v])
        {
            if (d[u] > dist + w)
            {
                d[u] = dist + w;
                p[u] = v;
                q.push(make_pair(d[u], u));
            }
        }
    }

    if (p[n] == -1)
    {
        cout << "-1" << '\n';
        return (0 ^ 0);
    }

    vector<int64_t> path;
    path.push_back(n);
    while (path.back() != 1)
        path.push_back(p[path.back()]);

    for (auto it = path.rbegin(); it != path.rend(); it++)
        cout << *it << ' ';
    cout << '\n';

    return (0 ^ 0);
}
