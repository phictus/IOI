// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 1000;
int64_t n, component[4 * maxn], componentCount;
string matrix[maxn];
vector<int64_t> adj[4 * maxn];

#define ROW(x) (x)
#define COL(x) ((x) + maxn)
#define NEG(x) (4 * maxn - (x) - 1)

inline void Init()
{
    componentCount = 0;

    for (int64_t i = 0; i < n; i++)
    {
        component[ROW(i)] = -1;
        component[COL(i)] = -1;
        component[NEG(ROW(i))] = -1;
        component[NEG(COL(i))] = -1;

        adj[ROW(i)].clear();
        adj[COL(i)].clear();
        adj[NEG(ROW(i))].clear();
        adj[NEG(COL(i))].clear();
    }
}

inline void AddEdge(int64_t v, int64_t u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
    adj[NEG(v)].push_back(NEG(u));
    adj[NEG(u)].push_back(NEG(v));
}

void DoDfs(int64_t v)
{
    component[v] = componentCount;
    for (int64_t u : adj[v])
    {
        if (component[u] == -1)
            DoDfs(u);
    }
}

void SetComponent(int64_t v)
{
    if (component[v] == -1)
    {
        DoDfs(v);
        componentCount++;
    }
}

bool SolveTestCase()
{
    cin >> n;
    for (int64_t i = 0; i < n; i++)
        cin >> matrix[i];

    Init();

    for (int64_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int64_t j = 0; j < n; j++)
        {
            if (matrix[i][j] == s[j])
                AddEdge(ROW(i), COL(j));
            else
                AddEdge(ROW(i), NEG(COL(j)));
        }
    }

    for (int64_t i = 0; i < n; i++)
    {
        SetComponent(ROW(i));
        SetComponent(COL(i));
        SetComponent(NEG(ROW(i)));
        SetComponent(NEG(COL(i)));
    }

    for (int64_t i = 0; i < n; i++)
    {
        if (component[ROW(i)] == component[NEG(ROW(i))])
            return false;
        if (component[COL(i)] == component[NEG(COL(i))])
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t testCase;
    cin >> testCase;
    while (testCase--)
    {
        if (SolveTestCase())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return (0 ^ 0);
}
