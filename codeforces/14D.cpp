// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>

using namespace std;

constexpr uint32_t maxn = 201;
uint32_t n;
vector<uint32_t> graph[maxn];

int32_t longestPathLength, longestPathVertex;
void dfs1(uint32_t v, uint32_t parent, uint32_t h, uint32_t banned)
{
    for (uint32_t e : graph[v])
        if (e != parent && e != banned)
            dfs1(e, v, h + 1, banned);

    if ((int32_t)h > longestPathLength)
    {
        longestPathLength = h;
        longestPathVertex = v;
    }
}

uint32_t longestPath(uint32_t u, uint32_t v)
{
    longestPathLength = -1;
    dfs1(u, u, 0, v);

    longestPathLength = -1;
    dfs1(longestPathVertex, longestPathVertex, 0, v);

    return longestPathLength;
}

uint32_t ans = 0;
void dfs2(uint32_t v, uint32_t parent)
{
    for (uint32_t e : graph[v])
        if (e != parent)
            dfs2(e, v);

    if (v != 1)
        ans = max(ans, longestPath(v, parent) * longestPath(parent, v));
}

int main()
{
    cin >> n;
    for (uint32_t i = 1; i < n; i++)
    {
        uint32_t u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs2(1, 1);

    cout << ans << endl;

    return (0 ^ 0);
}
