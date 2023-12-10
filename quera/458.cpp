// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <limits>
#include <queue>
#include <cstdint>

using namespace std;

struct Vertex
{
    int64_t i, j;
};

struct QueueType
{
    int64_t d;
    Vertex v;

    bool operator<(const QueueType& other) const
    {
        return d > other.d;
    }
};

constexpr int64_t maxn = 500, inf = numeric_limits<int64_t>::max();
int64_t n, m, a[maxn][maxn][4], cost[maxn][maxn][4], minimumSum = 0, dist[maxn][maxn];
bool isVisited[maxn][maxn];

void FindMinDist()
{
    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = 0; j < m; j++)
            dist[i][j] = inf;
    }

    constexpr int64_t di[4] = {0, 1, 0, -1};
    constexpr int64_t dj[4] = {1, 0, -1, 0};

    priority_queue<QueueType> q;
    q.push({0, {0, 0}});
    dist[0][0] = 0;

    while (!q.empty())
    {
        Vertex v = q.top().v;
        q.pop();

        if (isVisited[v.i][v.j])
            continue;
        isVisited[v.i][v.j] = true;

        for (int64_t k = 0; k < 4; k++)
        {
            Vertex u;
            u.i = v.i + di[k];
            u.j = v.j + dj[k];
            if (u.i < 0 || u.i >= n || u.j < 0 || u.j >= m)
                continue;

            if (isVisited[u.i][u.j])
                continue;
            if (dist[u.i][u.j] > dist[v.i][v.j] + cost[v.i][v.j][k])
            {
                dist[u.i][u.j] = dist[v.i][v.j] + cost[v.i][v.j][k];
                q.push({dist[u.i][u.j], u});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int64_t k = 0; k < 4; k++)
    {
        for (int64_t i = 0; i < n; i++)
        {
            for (int64_t j = 0; j < m; j++)
                cin >> a[i][j][k];
        }
    }

    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = 0; j < m; j++)
        {
            int64_t minimum = inf;
            for (int64_t k = 0; k < 4; k++)
                minimum = min(minimum, a[i][j][k]);

            for (int64_t k = 0; k < 4; k++)
                cost[i][j][k] = a[i][j][k] - minimum;
            minimumSum += minimum;
        }
    }

    FindMinDist();
    cout << minimumSum + dist[n - 1][m - 1] << '\n';

    return (0 ^ 0);
}
