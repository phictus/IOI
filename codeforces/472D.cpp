// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using SSPair = pair<uint16_t, uint16_t>;
using LSPair = pair<uint64_t, uint16_t>;
using Edge = pair<uint64_t, SSPair>;

constexpr uint16_t maxn = 2001;
uint16_t n;
uint64_t d[maxn][maxn];

vector<Edge> edges;
uint16_t parent[maxn];
vector<LSPair> adjacents[maxn];

void No()
{
    cout << "NO\n";
    exit(0);
}

uint16_t FindSet(uint16_t v)
{
    if (parent[v] == v)
        return v;

    parent[v] = FindSet(parent[v]);
    return parent[v];
}

void MakeTree()
{
    sort(edges.begin(), edges.end());
    for (uint16_t i = 1; i <= n; i++)
        parent[i] = i;

    for (const auto& [w, v] : edges)
    {
        uint64_t v1Set = FindSet(v.first);
        uint64_t v2Set = FindSet(v.second);
        if (v1Set == v2Set)
            continue;
        parent[v1Set] = v2Set;

        adjacents[v.first].push_back(make_pair(w, v.second));
        adjacents[v.second].push_back(make_pair(w, v.first));
    }
}

void DFS(uint16_t root, uint16_t vertex, uint16_t parent = 0, uint64_t distance = 0)
{
    if (distance != d[root][vertex])
        No();

    for (const auto& [weight, adj] : adjacents[vertex])
        if (adj != parent)
            DFS(root, adj, vertex, distance + weight);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (uint16_t i = 1; i <= n; i++)
    {
        for (uint16_t j = 1; j < i; j++)
        {
            cin >> d[i][j];
            if (d[i][j] != d[j][i])
                No();
        }

        cin >> d[i][i];
        if (d[i][i] != 0)
            No();

        for (uint16_t j = i + 1; j <= n; j++)
        {
            cin >> d[i][j];
            if (d[i][j] == 0)
                No();

            edges.push_back(make_pair(d[i][j], make_pair(i, j)));
        }
    }

    MakeTree();
    for (uint16_t i = 1; i <= n; i++)
        DFS(i, i);

    cout << "YES\n";

    return (0 ^ 0);
}
