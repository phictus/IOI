// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 1000000;
int64_t n, result[maxn + 1];
vector<int64_t> adj[maxn + 1];
vector<int64_t>* sack[maxn + 1];

inline int64_t& Get(int64_t sackId, int64_t depth)
{
    return (*sack[sackId])[sack[sackId]->size() - depth - 1];
}

void DoDfs(int64_t v, int64_t p = 0)
{
    int64_t bigChild = 0;
    for (int64_t u : adj[v])
    {
        if (u == p)
            continue;

        DoDfs(u, v);
        if (sack[bigChild]->size() < sack[u]->size())
            bigChild = u;
    }

    if (bigChild == 0)
    {
        sack[v] = new vector<int64_t>();
        sack[v]->push_back(1);
        return;
    }

    result[v] = result[bigChild] + 1;
    sack[v] = sack[bigChild];
    sack[bigChild] = nullptr;
    sack[v]->push_back(1);

    for (int64_t u : adj[v])
    {
        if (u == p || u == bigChild)
            continue;

        for (int64_t i = 1; i <= sack[u]->size(); i++)
        {
            Get(v, i) += Get(u, i - 1);

            if (Get(v, result[v]) < Get(v, i))
                result[v] = i;
            if (Get(v, result[v]) == Get(v, i) && i < result[v])
                result[v] = i;
        }

        delete sack[u];
    }

    if (Get(v, result[v]) == 1)
        result[v] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int64_t i = 1; i < n; i++)
    {
        int64_t v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    sack[0] = new vector<int64_t>();
    DoDfs(1);
    delete sack[0];
    delete sack[1];

    for (int64_t i = 1; i <= n; i++)
        cout << result[i] << ' ';
    cout << '\n';

    return (0 ^ 0);
}
