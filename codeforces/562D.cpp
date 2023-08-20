// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdio>
#include <cstdint>

using namespace std;

constexpr uint32_t maxn = 200001;
uint32_t parent[maxn];
uint32_t endOfSet[maxn];

uint32_t findSet(uint32_t v)
{
    if (v == parent[v])
        return v;
    parent[v] = findSet(parent[v]);

    return parent[v];
}

void unionSets(uint32_t v, uint32_t u)
{
    parent[findSet(v)] = findSet(u);
}

void unionInterval(uint32_t first, uint32_t last)
{
    uint32_t end = endOfSet[first];
    if (end >= last)
        return;

    unionSets(end + 1, end);
    unionInterval(end + 1, last);

    endOfSet[first] = endOfSet[last];
}

int main()
{
    uint32_t n, q;
    scanf("%u%u", &n, &q);

    for (uint32_t i = 1; i <= n; i++)
    {
        parent[i] = i;
        endOfSet[i] = i;
    }

    while (q--)
    {
        uint32_t o, x, y;
        scanf("%u%u%u", &o, &x, &y);

        if (o == 1)
            unionSets(x, y);
        else if (o == 2)
            unionInterval(x, y);
        else
        {
            if (findSet(x) == findSet(y))
                puts("YES");
            else
                puts("NO");
        }
    }

    return (0 ^ 0);
}
