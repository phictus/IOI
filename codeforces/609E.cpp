// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>
#include <cstring>

using namespace std;
using Pair = pair<uint64_t, uint32_t>;

struct Edge
{
    uint64_t Weight;
    uint32_t Vertex1, Vertex2;
};

constexpr uint32_t maxn = 200001;
constexpr uint32_t maxlogn = 18;
uint32_t n, m;
Edge edge[maxn];
vector<Pair> adjacents[maxn];

uint64_t mstWeight = 0;
vector<Pair> mstAdjacents[maxn];

uint32_t depth[maxn];
uint32_t ancestor[maxn][18];
uint64_t maxEdgeWeight[maxn][18];

void MakeMST()
{
    using QueueType = pair<uint64_t, pair<uint32_t, uint32_t>>;
    priority_queue<QueueType, vector<QueueType>, greater<QueueType>> q;

    bool isVisited[n + 1];
    memset(isVisited, 0, (n + 1) * sizeof(bool));

    Pair parent[n + 1];

    q.push({0, {0, 1}});
    parent[1] = make_pair(0, 0);

    while (!q.empty())
    {
        QueueType top = q.top();
        q.pop();

        if (isVisited[top.second.second])
            continue;

        isVisited[top.second.second] = true;
        mstWeight += top.first;
        parent[top.second.second] = make_pair(top.first, top.second.first);

        for (const Pair& adjacent : adjacents[top.second.second])
            if (!isVisited[adjacent.second])
                q.push({adjacent.first, {top.second.second, adjacent.second}});
    }

    for (uint32_t i = 2; i <= n; i++)
        mstAdjacents[parent[i].second].push_back(make_pair(parent[i].first, i));
}

void DFSOnMST(uint32_t vertex = 1, uint32_t parent = 0, uint32_t d = 0, uint64_t w = 0)
{
    depth[vertex] = d;

    ancestor[vertex][0] = parent;
    for (uint32_t i = 1; i < maxlogn; i++)
        ancestor[vertex][i] = ancestor[ancestor[vertex][i - 1]][i - 1];

    maxEdgeWeight[vertex][0] = w;
    for (uint32_t i = 1; i < maxlogn; i++)
        maxEdgeWeight[vertex][i] = max(maxEdgeWeight[vertex][i - 1], maxEdgeWeight[ancestor[vertex][i - 1]][i - 1]);

    for (const Pair& adjacent : mstAdjacents[vertex])
        DFSOnMST(adjacent.second, vertex, d + 1, adjacent.first);
}

uint64_t MaxEdgeWeight(uint32_t v, uint32_t u)
{
    uint64_t result = 0;

    if (depth[v] < depth[u])
        swap(v, u);

    for (int32_t i = maxlogn - 1; i >= 0; i--)
    {
        if (((depth[v] - depth[u]) >> i) & 1)
        {
            result = max(result, maxEdgeWeight[v][i]);
            v = ancestor[v][i];
        }
    }

    if (v != u)
    {
        for (int32_t i = maxlogn - 1; i >= 0; i--)
        {
            if (ancestor[v][i] != ancestor[u][i])
            {
                result = max(result, maxEdgeWeight[v][i]);
                result = max(result, maxEdgeWeight[u][i]);

                v = ancestor[v][i];
                u = ancestor[u][i];
            }
        }

        result = max(result, maxEdgeWeight[v][0]);
        result = max(result, maxEdgeWeight[u][0]);
    }

    return result;
}

int main()
{
    cin >> n >> m;
    for (uint32_t i = 1; i <= m; i++)
    {
        uint32_t v, u;
        uint64_t w;
        cin >> v >> u >> w;
        edge[i] = {w, v, u};
        adjacents[v].push_back(make_pair(w, u));
        adjacents[u].push_back(make_pair(w, v));
    }

    MakeMST();
    DFSOnMST();

    for (uint32_t i = 1; i <= m; i++)
        cout << mstWeight + edge[i].Weight - MaxEdgeWeight(edge[i].Vertex1, edge[i].Vertex2) << endl;

    return (0 ^ 0);
}
