// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

constexpr uint32_t maxn = 200001;
uint32_t n;
vector<uint32_t> graph[maxn];
bool mark[maxn];
uint32_t length, v1, v2;

uint32_t dfs1ResultVertex, dfs1ResultLength;
void dfs1(uint32_t vertex, uint32_t parent, uint32_t height)
{
    for (uint32_t e : graph[vertex])
        if (e != parent)
            dfs1(e, vertex, height + (uint32_t)(!mark[e]));

    if (height >= dfs1ResultLength)
    {
        dfs1ResultLength = height;
        dfs1ResultVertex = vertex;
    }
}

bool dfs2(uint32_t vertex, uint32_t parent)
{
    for (uint32_t e : graph[vertex])
        if (e != parent)
            if (dfs2(e, vertex))
            {
                mark[vertex] = true;
                break;
            }
    if (mark[vertex])
        return true;
    else
        return false;
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

    memset(mark, 0, n * sizeof(bool));

    dfs1ResultLength = 0;
    dfs1(1, 0, 0);
    v1 = dfs1ResultVertex;

    dfs1ResultLength = 0;
    dfs1(v1, 0, 0);
    v2 = dfs1ResultVertex;
    length = dfs1ResultLength;

    mark[v2] = true;
    dfs2(v1, 0);

    dfs1ResultLength = 0;
    dfs1(v1, 0, 0);

    if (dfs1ResultVertex == v1)
    {
        cout << length << endl;
        for (uint32_t i = 1; i <= n; i++)
            if (i != v1 && i != v2)
            {
                cout << i << ' ';
                break;
            }
        cout << v1 << ' ' << v2 << endl;
    }
    else
    {
        cout << length + dfs1ResultLength << endl;
        cout << v1 << ' ' << v2 << ' ' << dfs1ResultVertex << endl;
    }

    return (0 ^ 0);
}
