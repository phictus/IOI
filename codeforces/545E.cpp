// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstdint>
#include <cstring>

using namespace std;

struct Edge
{
    uint64_t Weight;
    uint32_t Vertex1;
    uint32_t Vertex2;
};

struct QueueType
{
    uint64_t Distance;
    uint64_t Weight;
    uint32_t Vertex;
    uint32_t Edge;
};

constexpr bool operator>(const QueueType& v1, const QueueType& v2)
{
    if (v1.Distance > v2.Distance)
        return true;
    else if (v1.Distance < v2.Distance)
        return false;
    else
        return v1.Weight > v2.Weight;
}

int main()
{
    uint32_t n, m;
    cin >> n >> m;

    vector<uint32_t> adjacentEdges[n + 1];
    Edge edge[m + 1];
    for (uint32_t i = 1; i <= m; i++)
    {
        uint32_t v, u;
        uint64_t w;
        cin >> v >> u >> w;

        edge[i].Weight = w;
        edge[i].Vertex1 = v;
        edge[i].Vertex2 = u;

        adjacentEdges[v].push_back(i);
        adjacentEdges[u].push_back(i);
    }

    priority_queue<QueueType, vector<QueueType>, greater<QueueType>> q;
    auto distance = vector<uint64_t>(n + 1, numeric_limits<uint64_t>::max());

    uint32_t root;
    cin >> root;
    q.push({0, 0, root, 0});

    uint64_t resultWeight = 0;
    vector<uint32_t> result;

    while (!q.empty())
    {
        QueueType top = q.top();
        q.pop();

        if (distance[top.Vertex] <= top.Distance)
            continue;
        distance[top.Vertex] = top.Distance;

        resultWeight += top.Weight;
        result.push_back(top.Edge);

        for (uint32_t adj : adjacentEdges[top.Vertex])
        {
            q.push({
                top.Distance + edge[adj].Weight,
                edge[adj].Weight,
                edge[adj].Vertex1 + edge[adj].Vertex2 - top.Vertex,
                adj
            });
        }
    }

    cout << resultWeight << endl;
    for (auto it = result.begin() + 1; it != result.end(); it++)
        cout << *it << ' ';
    cout << endl;

    return (0 ^ 0);
}
