// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 1310720;
vector<int64_t> adj[maxn];

void AddEdge(int64_t v, int64_t u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void CreateGraph()
{
    int64_t size = 16, inc = 20;
    int64_t v = 7, u = 2;

    for (int64_t i = 2; i <= 6; i++)
        AddEdge(1, i);
    for (int64_t i = 2; i < 6; i++)
        AddEdge(i, i + 1);
    AddEdge(2, 6);
    AddEdge(u, size);

    while (v + 5 < maxn)
    {
        AddEdge(v, u);
        AddEdge(v, v + 1);
        v++;
        AddEdge(v, u);
        AddEdge(v, u + 1);
        AddEdge(v, v + 1);

        v++;
        u++;

        if (v > size)
        {
            adj[v - 1].pop_back();
            adj[v].pop_back();

            size += inc;
            inc *= 2;

            AddEdge(size, u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    CreateGraph();

    int64_t a, b;
    cin >> a >> b;

    queue<int64_t> q;
    auto d = vector<int64_t>(maxn, -1);

    q.push(a);
    d[a] = 0;

    while(!q.empty())
    {
        int64_t v = q.front();
        q.pop();

        for (int64_t u : adj[v])
        {
            if (d[u] == -1)
            {
                q.push(u);
                d[u] = d[v] + 1;

                if (u == b)
                {
                    cout << d[b] << '\n';
                    return (0 ^ 0);
                }
            }
        }
    }

    return (0 ^ 0);
}
