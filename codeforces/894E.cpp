// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;

struct Edge
{
    int64_t v, u, w;
};

constexpr int64_t maxn = 1000000;
int64_t n, m, s, discoverTime = 1, startTime[maxn + 1], lowlink[maxn + 1], sccCount = 0, scc[maxn + 1], sccSum[maxn + 1], dp[maxn + 1];
Edge edge[maxn + 1];
vector<Pair> updateList[maxn + 1];
vector<int64_t> adj[maxn + 1], stack;
bool isOnStack[maxn + 1];

void FindScc(int64_t v)
{
    startTime[v] = discoverTime;
    lowlink[v] = discoverTime;
    discoverTime++;

    stack.push_back(v);
    isOnStack[v] = true;

    for (int64_t e : adj[v])
    {
        int64_t u = edge[e].v + edge[e].u - v;
        if (startTime[u] == 0)
        {
            FindScc(u);
            lowlink[v] = min(lowlink[v], lowlink[u]);
        }
        else if (isOnStack[u])
            lowlink[v] = min(lowlink[v], startTime[u]);
    }

    if (lowlink[v] == startTime[v])
    {
        sccCount++;
        int64_t u = 0;
        do
        {
            u = *stack.rbegin();
            stack.pop_back();
            isOnStack[u] = false;

            scc[u] = sccCount;
        }
        while (u != v);
    }
}

inline constexpr int64_t GetOverallWeight(int64_t w)
{
    int64_t l = 0, r = maxn;
    while (l + 1 != r)
    {
        int64_t mid = (l + r) / 2;
        if (w >= (mid * (mid + 1)) / 2)
            l = mid;
        else
            r = mid;
    }

    return r * w - ((r - 1) * r * (r + 1)) / 6;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int64_t i = 1; i <= m; i++)
    {
        cin >> edge[i].v >> edge[i].u >> edge[i].w;
        adj[edge[i].v].push_back(i);
    }
    cin >> s;

    for (int64_t i = 1; i <= n; i++)
    {
        if (startTime[i] == 0)
            FindScc(i);
    }

    for (int64_t i = 1; i <= m; i++)
    {
        if (scc[edge[i].v] == scc[edge[i].u])
            sccSum[scc[edge[i].v]] += GetOverallWeight(edge[i].w);
        else
            updateList[scc[edge[i].v]].push_back(make_pair(scc[edge[i].u], edge[i].w));
    }

    dp[1] = sccSum[1];
    for (int64_t i = 2; i <= sccCount; i++)
    {
        for (auto[j, w] : updateList[i])
            dp[i] = max(dp[i], dp[j] + w);
        dp[i] += sccSum[i];
    }
    cout << dp[scc[s]] << '\n';

    return (0 ^ 0);
}
