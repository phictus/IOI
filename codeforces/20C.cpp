// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstdint>
#include <cstring>

using namespace std;
using Pair = pair<uint64_t, uint32_t>;

int main()
{
    uint32_t n, m;
    cin >> n >> m;

    vector<Pair> adjacents[n + 1];
    for (uint32_t i = 0; i < m; i++)
    {
        uint32_t v, u;
        uint64_t w;
        cin >> v >> u >> w;
        adjacents[v].push_back(make_pair(w, u));
        adjacents[u].push_back(make_pair(w, v));
    }

    priority_queue<Pair, vector<Pair>, greater<Pair>> q;
    auto d = vector<uint64_t>(n + 1, numeric_limits<uint64_t>::max());
    uint32_t parent[n + 1];
    bool isVisited[n + 1];
    memset(isVisited, 0, (n + 1) * sizeof(bool));

    q.push(make_pair(0, 1));
    d[1] = 0;
    parent[1] = 0;

    while (!q.empty())
    {
        uint32_t vertex = q.top().second;
        q.pop();

        if (isVisited[vertex])
            continue;

        for (const Pair& adj : adjacents[vertex])
        {
            if (d[adj.second] > d[vertex] + adj.first)
            {
                d[adj.second] = d[vertex] + adj.first;
                parent[adj.second] = vertex;
                q.push(make_pair(d[adj.second], adj.second));
            }
        }
    }

    if (d[n] == numeric_limits<uint64_t>::max())
        cout << -1 << endl;
    else
    {
        vector<uint32_t> path;
        uint32_t head = n;
        while (parent[head] != 0)
        {
            path.push_back(head);
            head = parent[head];
        }
        path.push_back(head);

        for (auto it = path.rbegin(); it != path.rend(); it++)
            cout << *it << ' ';
        cout << endl;
    }

    return (0 ^ 0);
}
