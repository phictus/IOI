// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <limits>
#include <cstdint>

using namespace std;

struct Result
{
    int64_t min = numeric_limits<int64_t>::max();
    int64_t count;
};

constexpr int64_t maxn = 100000, mod = 1000000007;

int64_t n, m, cost[maxn + 1];
vector<int64_t> adj[maxn + 1];

int64_t sccCount = 0, sccId[maxn + 1];
int64_t discoveryTime = 1, lowlink[maxn + 1], startTime[maxn + 1];

vector<int64_t> stack;
bool isOnStack[maxn + 1];

Result result[maxn + 1];

void DoDfs(int64_t v)
{
    startTime[v] = discoveryTime;
    lowlink[v] = discoveryTime;
    discoveryTime++;

    stack.push_back(v);
    isOnStack[v] = true;

    for (int64_t u : adj[v])
    {
        if (startTime[u] == 0)
        {
            DoDfs(u);
            lowlink[v] = min(lowlink[v], lowlink[u]);
        }
        else if (isOnStack[u])
            lowlink[v] = min(lowlink[v], startTime[u]);
    }

    if (lowlink[v] == startTime[v])
    {
        int64_t u = 0;
        do
        {
            u = *stack.rbegin();
            stack.pop_back();
            isOnStack[u] = false;
            sccId[u] = sccCount;
        }
        while (u != v);

        sccCount++;
    }
}

void FindSCC()
{
    for (int64_t i = 1; i <= n; i++)
    {
        if (startTime[i] == 0)
            DoDfs(i);
    }
}

void Compute(int64_t v)
{
    if (result[sccId[v]].min > cost[v])
    {
        result[sccId[v]].min = cost[v];
        result[sccId[v]].count = 1;
    }
    else if (result[sccId[v]].min == cost[v])
        result[sccId[v]].count++;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int64_t i = 1; i <= n; i++)
        cin >> cost[i];
    cin >> m;
    for (int64_t i = 1; i <= m; i++)
    {
        int64_t v, u;
        cin >> v >> u;
        adj[v].push_back(u);
    }

    FindSCC();
    for (int64_t i = 1; i <= n; i++)
        Compute(i);

    int64_t result1 = 0, result2 = 1;
    for (int64_t i = 0; i < sccCount; i++)
    {
        result1 += result[i].min;
        result2 = (result2 * result[i].count) % mod;
    }
    cout << result1 << ' ' << result2 << '\n';

    return (0 ^ 0);
}
