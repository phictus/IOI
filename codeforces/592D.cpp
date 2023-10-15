// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;

constexpr int64_t maxn = 123457;
int64_t n, k;
vector<int64_t> adj[maxn];
bool isAttacked[maxn];

int64_t usefullEdgesCount = 0;
bool countUsefullEdges(int64_t v, int64_t p = 0)
{
    bool result = isAttacked[v];
    for (int64_t u : adj[v])
    {
        if (u != p)
        {
            if (countUsefullEdges(u, v))
            {
                result = true;
                usefullEdgesCount++;
            }
        }
    }

    return result;
}

bool check(const Pair& p1, const Pair& p2)
{
    if (p1.second == p2.second)
        return p1.first > p2.first;
    else
        return p1.second < p2.second;
}

Pair furthestAttackedVertex(int64_t v, int64_t p = 0)
{
    Pair result;
    if (isAttacked[v])
        result = make_pair(v, 0);
    else
        result = make_pair(-1, -1);

    for (int64_t u : adj[v])
    {
        if (u != p)
        {
            Pair r = furthestAttackedVertex(u, v);
            if (r.second == -1)
                continue;
            else
            {
                r.second++;
                if (check(result, r))
                    result = r;
            }
        }
    }

    return result;
}

int main()
{
    cin >> n >> k;
    for (int64_t i = 1; i < n; i++)
    {
        int64_t v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    int64_t root;
    memset(isAttacked, 0, (n + 1) * sizeof(bool));
    for (int64_t i = 0; i < k; i++)
    {
        cin >> root;
        isAttacked[root] = true;
    }

    countUsefullEdges(root);
    Pair r1 = furthestAttackedVertex(root);
    Pair r2 = furthestAttackedVertex(r1.first);
    cout << min(r1.first, r2.first) << '\n';
    cout << 2 * usefullEdgesCount - r2.second << '\n';

    return (0 ^ 0);
}
