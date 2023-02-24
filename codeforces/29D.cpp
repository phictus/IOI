// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

constexpr uint32_t maxn = 301;
uint32_t n;
vector<uint32_t> graph[maxn];
queue<uint32_t> destinations;
vector<uint32_t> paths[maxn];

#define AT(x, y) ((x - 1) + (y - 1) * (maxn))
uint16_t weight[maxn * maxn];

void check(uint32_t u, uint32_t v)
{
    if (weight[AT(u, v)] > 2 || weight[AT(v, u)] > 2)
    {
        cout << -1 << endl;
        exit(0);
    }
}

bool dfs(uint32_t vertex, uint32_t parent, uint32_t& pathIndex)
{
    for (uint32_t e : graph[vertex])
        if (e != parent)
            if (dfs(e, vertex, pathIndex))
            {
                paths[pathIndex].push_back(vertex);
                check(e, vertex);
                weight[AT(e, vertex)]++;
                weight[AT(vertex, e)]++;
                return true;
            }

    if (vertex == destinations.front())
    {
        paths[pathIndex].push_back(vertex);
        return true;
    }
    else
        return false;
}

int main()
{
    cin >> n;
    memset(weight, 0, maxn * maxn * sizeof(uint8_t));
    for (uint32_t i = 1; i < n; i++)
    {
        uint32_t u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    uint32_t k = 0;
    for (uint32_t i = 2; i <= n; i++)
        if (graph[i].size() == 1)
            k++;
    destinations.push(1);
    for (uint32_t i = 0; i < k; i++)
    {
        uint32_t v;
        cin >> v;
        destinations.push(v);
    }
    destinations.push(1);

    for (uint32_t i = 0; i <= k; i++)
    {
        uint32_t v = destinations.front();
        destinations.pop();
        dfs(v, 0, i);
        paths[i].pop_back();
    }

    cout << 1 << ' ';
    for (uint32_t i = 0; i <= k; i++)
        for (auto iter = paths[i].rbegin(); iter != paths[i].rend(); iter++)
            cout << *iter << ' ';
    cout << endl;

    return (0 ^ 0);
}
