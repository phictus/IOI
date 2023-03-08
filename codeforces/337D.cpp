// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

constexpr uint32_t maxn = 100001;
uint32_t n, m, d;
vector<uint32_t> graph[maxn];
uint32_t p[maxn];
uint32_t h[maxn];
uint8_t mark[maxn];
uint32_t v1, v2;

uint32_t dfsResultVertex, dfsResultLength;
void dfs(uint32_t vertex, uint32_t parent, uint32_t height)
{
    for (uint32_t adjacent : graph[vertex])
    {
        if (adjacent != parent)
            dfs(adjacent, vertex, height + 1);
    }

    if (height > dfsResultLength && binary_search(p, p + m, vertex))
    {
        dfsResultLength = height;
        dfsResultVertex = vertex;
    }
}

void bfs(uint32_t root)
{
    queue<uint32_t> q;
    q.push(root);
    h[root] = 1;

    while (!q.empty())
    {
        uint32_t vertex = q.front();
        q.pop();

        mark[vertex]++;
        if (h[vertex] > d)
            continue;

        for (uint32_t adjacent : graph[vertex])
            if (h[adjacent] == 0)
            {
                q.push(adjacent);
                h[adjacent] = h[vertex] + 1;
            }
    }
}

int main()
{
    cin >> n >> m >> d;
    for (uint32_t i = 0; i < m; i++)
        cin >> p[i];
    for (uint32_t i = 1; i < n; i++)
    {
        uint32_t u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    sort(p, p + m);

    if (m == 1)
    {
        memset(mark, 0, (n + 1) * sizeof(uint8_t));
        memset(h, 0, (n + 1) * sizeof(uint32_t));
        bfs(p[0]);

        uint32_t ans = 0;
        for (uint32_t i = 1; i <= n; i++)
            if (mark[i] == 1)
                ans++;
        cout << ans << endl;
    }
    else
    {
        dfsResultLength = 0;
        dfs(p[0], 0, 0);
        v1 = dfsResultVertex;

        dfsResultLength = 0;
        dfs(v1, 0, 0);
        v2 = dfsResultVertex;

        memset(mark, 0, (n + 1) * sizeof(uint8_t));
        memset(h, 0, (n + 1) * sizeof(uint32_t));
        bfs(v1);
        memset(h, 0, (n + 1) * sizeof(uint32_t));
        bfs(v2);

        uint32_t ans = 0;
        for (uint32_t i = 1; i <= n; i++)
            if (mark[i] == 2)
                ans++;
        cout << ans << endl;
    }

    return (0 ^ 0);
}
