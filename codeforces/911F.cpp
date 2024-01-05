// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 200000;
int64_t n, vert[2], dist[2][maxn + 1];
vector<int64_t> adj[maxn + 1], path;
bool isOnPath[maxn + 1];

struct FurthestResult
{
    int64_t vertex, length;

    bool operator<(const FurthestResult& other) const
    {
        return length < other.length;
    }
};

FurthestResult FindFurthest(int64_t v, int64_t p = 0)
{
    FurthestResult result = {v, 0};
    for (int64_t u : adj[v])
    {
        if (u != p)
        {
            auto x = FindFurthest(u, v);
            x.length++;
            result = max(result, x);
        }
    }

    return result;
}

void InitPath(int64_t v = vert[0], int64_t p = 0)
{
    if (v == vert[1])
        isOnPath[v] = true;

    for (int64_t u : adj[v])
    {
        if (u != p)
        {
            InitPath(u, v);
            if (isOnPath[u])
                isOnPath[v] = true;
        }
    }

    if (isOnPath[v])
        path.push_back(v);
}

void InitDist(int64_t v, int64_t type, int64_t p = 0)
{
    for (int64_t u : adj[v])
    {
        if (u != p)
        {
            dist[type][u] = dist[type][v] + 1;
            InitDist(u, type, v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int64_t i = 1; i < n; i++)
    {
        int64_t v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vert[0] = FindFurthest(1).vertex;
    vert[1] = FindFurthest(vert[0]).vertex;

    InitPath();
    path.pop_back();

    InitDist(vert[0], 0);
    InitDist(vert[1], 1);

    int64_t result = (path.size() * (path.size() + 1)) / 2;
    for (int64_t v = 1; v <= n; v++)
    {
        if (!isOnPath[v])
            result += max(dist[0][v], dist[1][v]);
    }
    cout << result << '\n';

    vector<int64_t> stack;
    for (int64_t v = 1; v <= n; v++)
    {
        if (!isOnPath[v])
            stack.push_back(v);
    }

    sort(stack.begin(), stack.end(),
        [&](int64_t x, int64_t y) {
            return dist[0][x] > dist[0][y];
        }
    );

    for (int64_t v : stack)
    {
        if (dist[0][v] > dist[1][v])
            cout << vert[0] << ' ' << v << ' ' << v << '\n';
        else
            cout << vert[1] << ' ' << v << ' ' << v << '\n';
    }

    for (int64_t v : path)
        cout << vert[0] << ' ' << v << ' ' << v << '\n';

    return (0 ^ 0);
}
