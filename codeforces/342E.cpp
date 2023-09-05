// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr uint32_t maxn = 100001, maxlogn = 18, maxsqrtn = 317;
uint32_t n, q;
vector<uint32_t> adjacents[maxn];
uint32_t depth[maxn];
uint32_t ancestor[maxn][maxlogn];

vector<uint32_t> potentials;
uint32_t shortestPath[maxn];

void initialize(uint32_t v = 1, uint32_t p = 0, uint32_t d = 0)
{
    depth[v] = d;
    shortestPath[v] = d;

    ancestor[v][0] = p;
    for (uint32_t i = 1; i < maxlogn; i++)
        ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];

    for (uint32_t adj : adjacents[v])
        if (adj != p)
            initialize(adj, v, d + 1);
}

void update()
{
    queue<uint32_t> q;
    for (uint32_t v : potentials)
        q.push(v);
    potentials.clear();

    while (!q.empty())
    {
        uint32_t v = q.front();
        q.pop();

        for (uint32_t adj : adjacents[v])
        {
            if (shortestPath[adj] > shortestPath[v] + 1)
            {
                shortestPath[adj] = shortestPath[v] + 1;
                q.push(adj);
            }
        }
    }
}

uint32_t lca(uint32_t v, uint32_t u)
{
    if (depth[v] < depth[u])
        swap(v, u);

    for (int32_t i = maxlogn - 1; i >= 0; i--)
        if (((depth[v] - depth[u]) >> i) & 1)
            v = ancestor[v][i];

    if (v == u)
        return u;

    for (int32_t i = maxlogn - 1; i >= 0; i--)
    {
        if (ancestor[v][i] != ancestor[u][i])
        {
            v = ancestor[v][i];
            u = ancestor[u][i];
        }
    }

    return ancestor[u][0];
}

uint32_t findClosestRed(uint32_t v)
{
    uint32_t result = shortestPath[v];
    for (uint32_t p : potentials)
        result = min(result, depth[v] + depth[p] - 2 * depth[lca(v, p)]);

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> q;
    for (uint32_t i = 1; i < n; i++)
    {
        uint32_t v, u;
        cin >> v >> u;
        adjacents[v].push_back(u);
        adjacents[u].push_back(v);
    }

    for (uint32_t i = 0; i < maxlogn; i++)
        ancestor[0][i] = 0;
    initialize();

    for (uint32_t i = 0; i < q; i++)
    {
        if (i % maxsqrtn == 0)
            update();

        uint32_t type, v;
        cin >> type >> v;

        if (type == 1)
        {
            potentials.push_back(v);
            shortestPath[v] = 0;
        }
        else
            cout << findClosestRed(v) << '\n';
    }

    return (0 ^ 0);
}
