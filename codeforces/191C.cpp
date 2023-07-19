// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

constexpr uint32_t maxn = 100001;
constexpr uint32_t maxlogn = 17;
vector<uint32_t> adjacents[maxn];
pair<uint32_t, uint32_t> edge[maxn];
uint32_t ancestor[maxn][maxlogn];
uint32_t depth[maxn];
int32_t result[maxn];

void Initialize(uint32_t vertex, uint32_t parent = 0, uint32_t d = 0)
{
    depth[vertex] = d;

    ancestor[vertex][0] = parent;
    for (uint32_t i = 1; i < maxlogn; i++)
        ancestor[vertex][i] = ancestor[ancestor[vertex][i - 1]][i - 1];

    for (uint32_t adjacent : adjacents[vertex])
        if (adjacent != parent)
            Initialize(adjacent, vertex, d + 1);
}

uint32_t LCA(uint32_t v, uint32_t u)
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

    return ancestor[v][0];
}

uint32_t DFS(uint32_t vertex, uint32_t parent = 0)
{
    for (uint32_t adjacent : adjacents[vertex])
        if (adjacent != parent)
            result[vertex] += DFS(adjacent, vertex);

    return result[vertex];
}

int main()
{
    uint32_t n;
    cin >> n;
    for (uint32_t i = 1; i < n; i++)
    {
        uint32_t v, u;
        cin >> v >> u;
        edge[i].first = v;
        edge[i].second = u;
        adjacents[v].push_back(u);
        adjacents[u].push_back(v);
    }

    Initialize(1);
    memset(result, 0, n * sizeof(int32_t));

    uint32_t k;
    cin >> k;
    while (k--)
    {
        uint32_t v, u;
        cin >> v >> u;
        result[v]++;
        result[u]++;
        result[LCA(v, u)] -= 2;
    }

    DFS(1);

    for (uint32_t i = 1; i < n; i++)
        cout << (depth[edge[i].first] > depth[edge[i].second] ? result[edge[i].first] : result[edge[i].second]) << endl;

    return (0 ^ 0);
}
