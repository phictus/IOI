// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;
using Pair = pair<uint64_t, uint64_t>;

void Dijkstra(uint64_t n, vector<Pair>* adjacents, uint64_t source)
{
    priority_queue<Pair, vector<Pair>, greater<Pair>> q;
    auto d = vector<uint64_t>(n + 1, numeric_limits<uint64_t>::max());
    bool isVisited[n + 1];
    memset(isVisited, 0, (n + 1) * sizeof(bool));

    q.push(make_pair(0, source));
    d[source] = 0;

    while (!q.empty())
    {
        Pair vertex = q.top();
        q.pop();

        if (isVisited[vertex.second])
            continue;
        else
            isVisited[vertex.second] = true;

        for (const Pair& adjacent : adjacents[vertex.second])
        {
            if (d[adjacent.first] > d[vertex.second] + adjacent.second)
            {
                d[adjacent.first] = d[vertex.second] + adjacent.second;
                q.push(make_pair(d[adjacent.first], adjacent.first));
            }
        }
    }

    for (uint64_t i = 1; i <= n; i++)
        printf("%llu\n", d[i]);
}

int main()
{
    uint64_t n, m;
    scanf("%llu%llu", &n, &m);

    vector<Pair> adjacents[n + 1];
    for (uint64_t i = 0; i < m; i++)
    {
        uint64_t v, u, w;
        scanf("%llu%llu%llu", &v, &u, &w);
        adjacents[v].push_back(make_pair(u, 2 * w));
        adjacents[u].push_back(make_pair(v, 2 * w));
    }
    for (uint64_t i = 1; i <= n; i++)
    {
        uint64_t a;
        scanf("%llu", &a);
        adjacents[0].push_back(make_pair(i, a));
        adjacents[i].push_back(make_pair(0, a));
    }

    Dijkstra(n, adjacents, 0);

    return (0 ^ 0);
}
