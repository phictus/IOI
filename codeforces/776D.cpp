// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100001;
int64_t n, m, firstSwitch[maxn], component[2 * maxn], componentCount = 0;
bool isOpen[maxn];
vector<int64_t> adj[2 * maxn];

#define NEG(x) (2 * maxn - (x))

inline void AddEdge(int64_t v, int64_t u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
    adj[NEG(v)].push_back(NEG(u));
    adj[NEG(u)].push_back(NEG(v));
}

void FindComponent(int64_t v)
{
    component[v] = componentCount;
    for (int64_t u : adj[v])
    {
        if (component[u] == 0)
            FindComponent(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> m >> n;
    for (int64_t i = 1; i <= m; i++)
        cin >> isOpen[i];
    for (int64_t i = 1; i <= n; i++)
    {
        int64_t length;
        cin >> length;
        for (int64_t j = 1; j <= length; j++)
        {
            int64_t v;
            cin >> v;
            if (firstSwitch[v] == 0)
                firstSwitch[v] = i;
            else
            {
                if (isOpen[v])
                    AddEdge(firstSwitch[v], i);
                else
                    AddEdge(firstSwitch[v], NEG(i));
            }
        }
    }

    for (int64_t i = 1; i <= n; i++)
    {
        if (component[i] == 0)
        {
            componentCount++;
            FindComponent(i);
        }

        if (component[NEG(i)] == 0)
        {
            componentCount++;
            FindComponent(NEG(i));
        }
    }

    for (int64_t i = 1; i <= n; i++)
    {
        if (component[i] == component[NEG(i)])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return (0 ^ 0);
}
