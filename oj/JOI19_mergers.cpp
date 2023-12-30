// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 500001;
int64_t n, k, state[maxn], currentTime = 1, discovery[maxn], depth[maxn], parent[maxn];
vector<int64_t> adj[maxn], cities[maxn];
set<int64_t> adjStates[maxn];

class Dsu
{
public:
    Dsu()
    {
        for (int64_t i = 1; i <= maxn; i++)
            _parent[i] = i;
    }

    int64_t FindSet(int64_t v)
    {
        if (_parent[v] == v)
            return v;

        return _parent[v] = FindSet(_parent[v]);
    }

    void Unite(int64_t v, int64_t u)
    {
        v = FindSet(v);
        u = FindSet(u);
        if (v == u)
            return;

        _parent[v] = u;
    }

private:
    int64_t _parent[maxn];
} dsu;

void Init(int64_t v = 1, int64_t p = 0)
{
    discovery[v] = currentTime++;
    depth[v] = depth[p] + 1;
    parent[v] = p;

    for (int64_t u : adj[v])
    {
        if (u != p)
            Init(u, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int64_t i = 1; i < n; i++)
    {
        int64_t v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for (int64_t i = 1; i <= n; i++)
    {
        cin >> state[i];
        cities[state[i]].push_back(i);
    }

    Init();

    for (int64_t i = 1; i <= k; i++)
    {
        sort(cities[i].begin(), cities[i].end(), [&](int64_t v, int64_t u) { return discovery[v] < discovery[u]; });
        for (int64_t j = 0; j + 1 < cities[i].size(); j++)
        {
            int64_t v = cities[i][j], u = cities[i][j + 1];
            if (depth[v] < depth[u])
                swap(v, u);

            while (depth[v] > depth[u])
            {
                dsu.Unite(state[v], state[parent[v]]);
                v = parent[v];
            }

            while (v != u)
            {
                dsu.Unite(state[v], state[parent[v]]);
                v = parent[v];

                dsu.Unite(state[u], state[parent[u]]);
                u = parent[u];
            }
        }
    }

    for (int64_t v = 1; v <= n; v++)
        state[v] = dsu.FindSet(state[v]);

    for (int64_t v = 1; v <= n; v++)
    {
        for (int64_t u : adj[v])
        {
            if (state[v] != state[u])
                adjStates[state[v]].insert(state[u]);
        }
    }

    int64_t result = 0;
    for (int64_t i = 1; i <= k; i++)
    {
        if (adjStates[i].size() == 1)
            result++;
    }
    cout << (result + 1) / 2 << '\n';

    return (0 ^ 0);
}
