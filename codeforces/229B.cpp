// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <cstdint>
#include <cstring>

using namespace std;
using Pair = pair<uint64_t, uint32_t>;

constexpr uint32_t maxn = 100001;
vector<Pair> adjacents[maxn];
vector<uint64_t> arrivals[maxn];
uint64_t d[maxn];

int main()
{
    uint32_t n, m;
    cin >> n >> m;

    for (uint32_t i = 0; i < m; i++)
    {
        uint32_t v, u;
        uint64_t w;
        cin >> v >> u >> w;
        adjacents[v].push_back(make_pair(w, u));
        adjacents[u].push_back(make_pair(w, v));
    }

    for (uint32_t i = 1; i <= n; i++)
    {
        uint32_t k;
        cin >> k;
        for (uint32_t j = 0; j < k; j++)
        {
            uint64_t c;
            cin >> c;
            arrivals[i].push_back(c);
        }
    }

    priority_queue<Pair, vector<Pair>, greater<Pair>> q;
    fill(d + 1, d + n + 1, numeric_limits<uint64_t>::max());

    q.push(make_pair(0, 1));
    d[1] = 0;

    while (!q.empty())
    {
        uint32_t vertex = q.top().second;
        uint64_t distance = q.top().first;
        q.pop();

        if (d[vertex] < distance)
            continue;

        while (binary_search(arrivals[vertex].begin(), arrivals[vertex].end(), distance))
            distance++;

        for (const Pair& adj : adjacents[vertex])
        {
            if (d[adj.second] > distance + adj.first)
            {
                d[adj.second] = distance + adj.first;
                q.push(make_pair(d[adj.second], adj.second));
            }
        }
    }

    if (d[n] == numeric_limits<uint64_t>::max())
        cout << -1 << endl;
    else
        cout << d[n] << endl;

    return (0 ^ 0);
}
