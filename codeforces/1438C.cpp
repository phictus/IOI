// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

struct Vertex
{
    int64_t x, y, neg;
};

constexpr int64_t maxn = 100;
int64_t n, m, a[maxn][maxn], sccCount = 0, scc[maxn][maxn][2], flag[maxn * maxn * 2];
Vertex root[maxn * maxn * 2];
vector<Vertex> adj[maxn][maxn][2], revAdj[maxn][maxn][2], discovery;
bool isVisited[maxn][maxn][2];

inline void AddEdge(const Vertex& v, const Vertex& u)
{
    adj[v.x][v.y][v.neg].push_back(u);
    revAdj[u.x][u.y][u.neg].push_back(v);
}

inline void AddImplication(const Vertex& v, const Vertex& u)
{
    AddEdge(v, u);
    AddEdge({u.x, u.y, 1 - u.neg}, {v.x, v.y, 1 - v.neg});
}

void Reset()
{
    for (int64_t i = 0; i < sccCount; i++)
        flag[i] = 0;
    sccCount = 0;

    discovery.clear();
    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = 0; j < m; j++)
        {
            for (int64_t k = 0; k < 2; k++)
            {
                adj[i][j][k].clear();
                revAdj[i][j][k].clear();
                isVisited[i][j][k] = false;
            }
        }
    }
}

void InitDiscovery(const Vertex& v)
{
    isVisited[v.x][v.y][v.neg] = true;

    for (const Vertex& u : adj[v.x][v.y][v.neg])
    {
        if (!isVisited[u.x][u.y][u.neg])
            InitDiscovery(u);
    }

    discovery.push_back(v);
}

void DoDfs(const Vertex& v)
{
    isVisited[v.x][v.y][v.neg] = true;

    for (const Vertex& u : revAdj[v.x][v.y][v.neg])
    {
        if (!isVisited[u.x][u.y][u.neg])
        {
            scc[u.x][u.y][u.neg] = scc[v.x][v.y][v.neg];
            DoDfs(u);
        }
    }
}

void FindScc()
{
    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = 0; j < m; j++)
        {
            for (int64_t k = 0; k < 2; k++)
            {
                if (!isVisited[i][j][k])
                    InitDiscovery({i, j, k});
            }
        }
    }

    reverse(discovery.begin(), discovery.end());
    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = 0; j < m; j++)
        {
            for (int64_t k = 0; k < 2; k++)
                isVisited[i][j][k] = false;
        }
    }

    for (const Vertex& v : discovery)
    {
        if (!isVisited[v.x][v.y][v.neg])
        {
            root[sccCount] = v;
            scc[v.x][v.y][v.neg] = sccCount++;
            DoDfs(v);
        }
    }
}

void SolveTestCase()
{
    cin >> n >> m;
    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = 0; j < m; j++)
            cin >> a[i][j];
    }

    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = 1; j < m; j++)
        {
            if (a[i][j] == a[i][j - 1])
            {
                AddImplication({i, j, 1}, {i, j - 1, 0});
                AddImplication({i, j - 1, 0}, {i, j, 1});
            }
            else if (a[i][j] + 1 == a[i][j - 1])
                AddImplication({i, j, 0}, {i, j - 1, 0});
            else if (a[i][j] - 1 == a[i][j - 1])
                AddImplication({i, j - 1, 0}, {i, j, 0});
        }
    }

    for (int64_t j = 0; j < m; j++)
    {
        for (int64_t i = 1; i < n; i++)
        {
            if (a[i][j] == a[i - 1][j])
            {
                AddImplication({i, j, 1}, {i - 1, j, 0});
                AddImplication({i - 1, j, 0}, {i, j, 1});
            }
            else if (a[i][j] + 1 == a[i - 1][j])
                AddImplication({i, j, 0}, {i - 1, j, 0});
            else if (a[i][j] - 1 == a[i - 1][j])
                AddImplication({i - 1, j, 0}, {i, j, 0});
        }
    }

    FindScc();

    for (int64_t i = sccCount - 1; i >= 0; i--)
    {
        if (flag[i] == 0)
        {
            flag[i] = 1;
            const Vertex v = root[i];
            flag[scc[v.x][v.y][1 - v.neg]] = 2;
        }
    }

    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = 0; j < m; j++)
        {
            if (flag[scc[i][j][0]] == 1)
                a[i][j]++;
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    Reset();
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
