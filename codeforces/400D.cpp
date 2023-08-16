// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>

using namespace std;
using Pair = pair<uint32_t, uint32_t>;

constexpr uint32_t maxn = 100001;
constexpr uint32_t maxk = 501;

uint32_t n, m, k;
uint32_t c[maxn];

uint32_t parent[maxn];

vector<Pair> adjacents[maxk];
uint32_t d[maxk][maxk];

uint32_t FindSet(uint32_t v)
{
    if (parent[v] == v)
        return v;
    else
        return parent[v] = FindSet(parent[v]);
}

void UnionSets(uint32_t v, uint32_t u)
{
    v = FindSet(v);
    u = FindSet(u);

    parent[v] = u;
}

void Dijkstra(uint32_t root)
{
    priority_queue<Pair, vector<Pair>, greater<Pair>> q;
    fill(d[root], d[root] + maxk, numeric_limits<uint32_t>::max());

    q.push(make_pair(0, root));
    d[root][root] = 0;

    while (!q.empty())
    {
        Pair top = q.top();
        q.pop();

        if (top.first > d[root][top.second])
            continue;

        for (const Pair& adj : adjacents[top.second])
        {
            if (d[root][adj.second] > d[root][top.second] + adj.first)
            {
                d[root][adj.second] = d[root][top.second] + adj.first;
                q.push(make_pair(d[root][adj.second], adj.second));
            }
        }
    }
}

int main()
{
    scanf("%u%u%u", &n, &m, &k);

    uint32_t offset = 1;
    for (uint32_t i = 1; i <= k; i++)
    {
        uint32_t v;
        scanf("%u", &v);

        fill(c + offset, c + offset + v, i);
        offset += v;
    }

    for (uint32_t i = 1; i <= n; i++)
        parent[i] = i;

    for (uint32_t i = 0; i < m; i++)
    {
        uint32_t v, u, w;
        scanf("%u%u%u", &v, &u, &w);

        if (c[v] != c[u])
        {
            adjacents[c[v]].push_back(make_pair(w, c[u]));
            adjacents[c[u]].push_back(make_pair(w, c[v]));
        }

        if (w == 0)
            UnionSets(v, u);
    }

    uint32_t set = FindSet(1);
    for (uint32_t i = 2; i <= n; i++)
    {
        if (c[i] != c[i - 1])
            set = FindSet(i);
        else if (FindSet(i) != set)
        {
            puts("No");
            return 0;
        }
    }

    for (uint32_t i = 1; i <= k; i++)
        Dijkstra(i);

    puts("Yes");
    for (uint32_t i = 1; i <= k; i++)
    {
        for (uint32_t j = 1; j <= k; j++)
        {
            if (d[i][j] == numeric_limits<uint32_t>::max())
                printf("-1 ");
            else
                printf("%u ", d[i][j]);
        }
        printf("\n");
    }

    return (0 ^ 0);
}
