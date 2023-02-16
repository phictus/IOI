// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

constexpr uint32_t maxn = 401;
uint32_t n, m;
bool graph[maxn][maxn];
uint32_t height[maxn];
bool railway;

bool check(uint32_t u, uint32_t v)
{
    if (railway)
        return graph[u][v];
    else
        return !graph[u][v];
}

bool bfs()
{
    queue<uint32_t> q;
    q.push(1);
    height[1] = 1;

    while (!q.empty())
    {
        uint32_t v = q.front();
        q.pop();
        if (v == n)
            return true;

        for (uint32_t i = 1; i <= n; i++)
            if (check(v, i) && height[i] == 0)
            {
                q.push(i);
                height[i] = height[v] + 1;
            }
    }

    return false;
}

int main()
{
    cin >> n >> m;
    for (uint32_t i = 1; i <= n; i++)
        for (uint32_t j = 1; j <= n; j++)
            graph[i][j] = false;
    for (uint32_t i = 0; i < m; i++)
    {
        uint32_t u, v;
        cin >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }

    if (graph[1][n])
        railway = false;
    else
        railway = true;
    memset(height, 0, n * sizeof(uint32_t));

    if (!bfs())
        cout << -1 << endl;
    else
        cout << height[n] - 1 << endl;

    return (0 ^ 0);
}
