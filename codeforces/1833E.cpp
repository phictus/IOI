// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdint>
#include <cstdio>
#include <map>

using namespace std;
using Pair = pair<uint32_t, uint32_t>;

constexpr uint32_t maxn = 200001;
uint32_t parent[maxn];

uint32_t FindSet(uint32_t v)
{
    if (parent[v] == v)
        return v;

    parent[v] = FindSet(parent[v]);
    return parent[v];
}

int main()
{
    uint32_t t;
    scanf("%u", &t);

    while (t--)
    {
        uint32_t n;
        scanf("%u", &n);

        for (uint32_t i = 1; i <= n; i++)
            parent[i] = i;
        map<Pair, bool> isAdjacent;

        uint32_t components = n, cycles = 0;
        for (uint32_t i = 1; i <= n; i++)
        {
            uint32_t a;
            scanf("%u", &a);

            if (FindSet(a) == FindSet(i))
            {
                if (!isAdjacent[make_pair(a, i)])
                    cycles++;
            }
            else
            {
                components--;
                isAdjacent[make_pair(a, i)] = true;
                isAdjacent[make_pair(i, a)] = true;
                parent[FindSet(a)] = FindSet(i);
            }
        }
        if (components == cycles)
            printf("%u %u\n", cycles, components);
        else
            printf("%u %u\n", cycles + 1, components);
    }

    return (0 ^ 0);
}
