// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

struct Path
{
    int64_t length, sum;
};

constexpr int64_t maxn = 200000;
int64_t n, m, w[maxn];
vector<int64_t> adj[maxn];

int64_t discoverTime, startTime[maxn], lowlink[maxn];
bool isOnStack[maxn];
vector<int64_t> stack;
int64_t sccCount, scc[maxn], sccLength[maxn], sccSum[maxn];

vector<int64_t> updateList[maxn];
Path dp[maxn];

void DoDfs(int64_t v)
{
    startTime[v] = discoverTime;
    lowlink[v] = discoverTime;
    discoverTime++;

    stack.push_back(v);
    isOnStack[v] = true;

    for (int64_t u : adj[v])
    {
        if (startTime[u] == -1)
        {
            DoDfs(u);
            lowlink[v] = min(lowlink[v], lowlink[u]);
        }
        else if (isOnStack[u])
            lowlink[v] = min(lowlink[v], startTime[u]);
    }

    if (startTime[v] == lowlink[v])
    {
        int64_t u;
        sccLength[sccCount] = 0;
        sccSum[sccCount] = 0;

        do
        {
            u = *stack.rbegin();
            stack.pop_back();
            isOnStack[u] = false;

            scc[u] = sccCount;
            sccLength[sccCount]++;
            sccSum[sccCount] += w[u];
        }
        while (v != u);

        sccCount++;
    }
}

void FindScc()
{
    discoverTime = 0;
    sccCount = 0;
    for (int64_t i = 0; i < n; i++)
    {
        startTime[i] = -1;
        isOnStack[i] = false;
    }

    for (int64_t i = 0; i < n; i++)
    {
        if (startTime[i] == -1)
            DoDfs(i);
    }
}

void InitUpdateList(int64_t v)
{
    startTime[v] = -1;

    for (int64_t u : adj[v])
    {
        updateList[scc[u]].push_back(scc[v]);
        if (startTime[u] != -1)
            InitUpdateList(u);
    }
}

void SolveTestCase()
{
    cin >> n >> m;
    for (int64_t i = 0; i < n; i++)
        cin >> w[i];
    for (int64_t i = 0; i < n; i++)
        adj[i].clear();
    for (int64_t i = 0; i < m; i++)
    {
        int64_t v, u;
        cin >> v >> u;
        adj[v - 1].push_back(u - 1);
    }

    FindScc();

    for (int64_t i = 0; i < n; i++)
        updateList[i].clear();
    for (int64_t i = 0; i < n; i++)
    {
        if (startTime[i] != -1)
            InitUpdateList(i);
    }

    for (int64_t i = sccCount - 1; i >= 0; i--)
    {
        dp[i] = {0, 0};
        for (int64_t j : updateList[i])
        {
            bool condition =
                (dp[i].length < dp[j].length) ||
                (dp[i].length == dp[j].length && dp[i].sum > dp[j].sum);

            if (condition)
                dp[i] = dp[j];
        }

        dp[i].length += sccLength[i];
        dp[i].sum += sccSum[i];
    }

    Path result = dp[0];
    for (int64_t i = 1; i < n; i++)
    {
        bool condition =
            (result.length < dp[i].length) ||
            (result.length == dp[i].length && result.sum > dp[i].sum);

        if (condition)
            result = dp[i];
    }

    cout << result.length << ' ' << result.sum << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t testCase;
    cin >> testCase;
    while (testCase--)
        SolveTestCase();

    return (0 ^ 0);
}
