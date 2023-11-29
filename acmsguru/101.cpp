// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

struct Edge
{
    int64_t v, u;
};

struct Result
{
    int64_t edge;
    char sign;
};

constexpr int64_t maxn = 6, maxm = 100;
int64_t m;
Edge edge[maxm + 1];
vector<int64_t> adj[maxn + 1];
bool isVisited[maxn + 1], isConnected[maxm + 1];
vector<Result> result;

void DoDfs(int64_t v)
{
    isVisited[v] = true;
    for (int64_t e : adj[v])
    {
        int64_t u = edge[e].v + edge[e].u - v;
        if (!isVisited[u])
            DoDfs(u);
    }
}

int64_t FindStart()
{
    int64_t oddCount = 0, oddVertex, nonZeroVertex;
    bool isNonZero[maxn + 1];

    for (int64_t i = 0; i <= maxn; i++)
    {
        if (adj[i].size() % 2 == 1)
        {
            oddCount++;
            oddVertex = i;
        }

        if (adj[i].size() > 0)
        {
            nonZeroVertex = i;
            isNonZero[i] = true;
        }
        else
            isNonZero[i] = false;
    }

    DoDfs(nonZeroVertex);
    for (int64_t i = 0; i <= maxn; i++)
    {
        if (isNonZero[i] && !isVisited[i])
            return -1;
    }

    if (oddCount == 2)
        return oddVertex;
    else if (oddCount == 0)
        return nonZeroVertex;

    return -1;
}

void FindTrail(int64_t v)
{
    while (!adj[v].empty())
    {
        int64_t e = *adj[v].rbegin();
        adj[v].pop_back();
        if (isConnected[e])
            continue;
        isConnected[e] = true;

        int64_t u = edge[e].v + edge[e].u - v;
        FindTrail(u);

        char sign = v == edge[e].v ? '-' : '+';
        result.push_back({e, sign});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> m;
    for (int64_t i = 1; i <= m; i++)
    {
        cin >> edge[i].v >> edge[i].u;
        adj[edge[i].v].push_back(i);
        adj[edge[i].u].push_back(i);
    }

    int64_t start = FindStart();
    if (start == -1)
    {
        cout << "No solution\n";
        return 0;
    }

    FindTrail(start);
    for (Result& e : result)
        cout << e.edge << ' ' << e.sign << '\n';

    return (0 ^ 0);
}
