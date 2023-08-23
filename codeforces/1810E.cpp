// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdio>
#include <cstdint>
#include <vector>
#include <queue>

using namespace std;
using Pair = pair<uint32_t, uint32_t>;

constexpr uint32_t maxn = 200001;
uint32_t n, m;
uint32_t danger[maxn];
vector<uint32_t> adjacents[maxn];
uint32_t mark[maxn];

bool dijkstra(uint32_t root)
{
    uint32_t vertices = 0;
    priority_queue<Pair, vector<Pair>, greater<Pair>> q;
    q.push(make_pair(0, root));

    while (!q.empty())
    {
        uint32_t top = q.top().second;
        q.pop();

        if (mark[top] == root)
            continue;
        mark[top] = root;

        if (danger[top] > vertices)
            return vertices == n;
        vertices++;

        for (uint32_t adj : adjacents[top])
            if (mark[adj] != root)
                q.push(make_pair(danger[adj], adj));
    }

    return vertices == n;
}

int main()
{
    uint32_t t;
    scanf("%u", &t);
    while (t--)
    {
        vector<uint32_t> roots;

        scanf("%u%u", &n, &m);
        for (uint32_t i = 1; i <= n; i++)
        {
            scanf("%u", &danger[i]);
            if (danger[i] == 0)
                roots.push_back(i);

            adjacents[i].clear();
            mark[i] = 0;
        }
        for (uint32_t i = 1; i <= m; i++)
        {
            uint32_t v, u;
            scanf("%u%u", &v, &u);
            adjacents[v].push_back(u);
            adjacents[u].push_back(v);
        }

        bool result = false;
        for (uint32_t root : roots)
        {
            if (mark[root] == 0)
            {
                if (dijkstra(root))
                {
                    result = true;
                    break;
                }
            }
        }

        if (result)
            puts("YES");
        else
            puts("NO");
    }

    return (0 ^ 0);
}
