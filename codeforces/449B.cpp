// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstdint>

using namespace std;

struct Type
{
    uint64_t Weight;
    uint32_t Train;
    uint32_t Vertex;
};

constexpr bool operator>(const Type& v1, const Type& v2)
{
    if (v1.Weight > v2.Weight)
        return true;
    else if (v1.Weight < v2.Weight)
        return false;
    else
        return v1.Train > v2.Train;
}

int main()
{
    uint32_t n, m, k;
    cin >> n >> m >> k;

    vector<Type> adjacents[n + 1];
    for (uint32_t i = 0; i < m; i++)
    {
        uint32_t v, u;
        uint64_t w;
        cin >> v >> u >> w;
        adjacents[v].push_back({w, 0, u});
        adjacents[u].push_back({w, 0, v});
    }
    for (uint32_t i = 0; i < k; i++)
    {
        uint32_t v;
        uint64_t w;
        cin >> v >> w;
        adjacents[v].push_back({w, 1, 1});
        adjacents[1].push_back({w, 1, v});
    }

    priority_queue<Type, vector<Type>, greater<Type>> q;
    auto distance = vector<uint64_t>(n + 1, numeric_limits<uint64_t>::max());

    q.push({0, 0, 1});
    uint32_t result = 0;

    while (!q.empty())
    {
        Type top = q.top();
        q.pop();

        if (distance[top.Vertex] <= top.Weight)
            continue;
        distance[top.Vertex] = top.Weight;

        result += top.Train;

        for (const Type& adj : adjacents[top.Vertex])
            q.push({top.Weight + adj.Weight, adj.Train, adj.Vertex});
    }

    cout << k - result << endl;

    return (0 ^ 0);
}
