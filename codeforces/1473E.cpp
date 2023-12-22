// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <cstdint>

using namespace std;

struct Edge
{
    int64_t v, w;
};

struct QueueType
{
    int64_t v, c1, c2, d;

    bool operator<(const QueueType& other) const
    {
        return d > other.d;
    }
};

constexpr int64_t maxn = 200001, inf = numeric_limits<int64_t>::max();
int64_t n, m, result[maxn];
vector<Edge> adj[maxn];
bool isVisited[maxn][2][2];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int64_t i = 0; i < m; i++)
    {
        int64_t v, u, w;
        cin >> v >> u >> w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }

    priority_queue<QueueType> q;
    q.push({1, 0, 0, 0});
    while (!q.empty())
    {
        auto[v, c1, c2, d] = q.top();
        q.pop();

        if (isVisited[v][c1][c2])
            continue;
        isVisited[v][c1][c2] = true;

        if (c1 == 1 && c2 == 1)
            result[v] = d;

        for (auto[u, w] : adj[v])
        {
            for (int64_t i = 0; i < 2 - c1; i++)
            {
                for (int64_t j = 0; j < 2 - c2; j++)
                {
                    if (isVisited[u][c1 + i][c2 + j])
                        continue;

                    q.push({u, c1 + i, c2 + j, d + w - i * w + j * w});
                }
            }
        }
    }

    for (int64_t v = 2; v <= n; v++)
        cout << result[v] << ' ';
    cout << '\n';

    return (0 ^ 0);
}
