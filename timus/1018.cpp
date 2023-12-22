// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

struct Edge
{
    int64_t u, w;
};

constexpr int64_t maxn = 100;
int64_t n, q, cnt[maxn + 1], dp[maxn + 1][maxn + 1];
vector<Edge> adj[maxn + 1];

void DoDfs(int64_t v, int64_t p = 0)
{
    if (adj[v].size() == 1)
    {
        cnt[v] = 1;
        return;
    }

    vector<Edge> child;
    for (Edge e : adj[v])
    {
        if (e.u != p)
        {
            DoDfs(e.u, v);
            child.push_back(e);
        }
    }

    int64_t u1 = child[0].u, w1 = child[0].w, u2 = child[1].u, w2 = child[1].w;
    cnt[v] = cnt[u1] + cnt[u2] + 1;

    for (int64_t i = 1; i <= cnt[u1]; i++)
        dp[v][i + 1] = max(dp[v][i + 1], dp[u1][i] + w1);
    for (int64_t i = 1; i <= cnt[u2]; i++)
        dp[v][i + 1] = max(dp[v][i + 1], dp[u2][i] + w2);

    for (int64_t i = 1; i <= cnt[u1]; i++)
    {
        for (int64_t j = 1; j <= cnt[u2]; j++)
            dp[v][i + j + 1] = max(dp[v][i + j + 1], dp[u1][i] + w1 + dp[u2][j] + w2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> q;
    for (int64_t i = 1; i < n; i++)
    {
        int64_t v, u, w;
        cin >> v >> u >> w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }

    DoDfs(1);
    cout << dp[1][q + 1] << '\n';

    return (0 ^ 0);
}
