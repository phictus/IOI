// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <queue>
#include <cstdint>

using namespace std;

struct Edge
{
    int64_t u, w;
};

constexpr int64_t maxn = 100000;
int64_t n, m, s, l, k, dist[maxn + 1];
vector<Edge> adj[maxn + 1];
bool isVisited[maxn + 1];

int64_t FindMax()
{
    int64_t result = 0;

    queue<int64_t> q;
    dist[s] = 0;
    isVisited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int64_t v = q.front();
        q.pop();

        for (auto[u, w] : adj[v])
        {
            result = max(result, w);

            if (!isVisited[u])
            {
                dist[u] = dist[v] + 1;
                isVisited[u] = true;

                if (dist[u] < k)
                    q.push(u);
            }
        }
    }

    return result;
}

void SolveTestCase()
{
    cin >> n >> m >> s >> l >> k;
    for (int64_t i = 1; i <= n; i++)
    {
        adj[i].clear();
        isVisited[i] = false;
    }
    for (int64_t i = 1; i <= m; i++)
    {
        int64_t v, u, w;
        cin >> v >> u >> w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }

    cout << FindMax() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("path.in", "r", stdin);

    int64_t testCase;
    cin >> testCase;
    while (testCase--)
        SolveTestCase();

    return (0 ^ 0);
}
