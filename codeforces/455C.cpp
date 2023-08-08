// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <vector>
#include <cstdio>
#include <cstdint>
#include <cstring>

using namespace std;

constexpr uint32_t maxn = 300001;
uint32_t n, m, q;
vector<uint32_t> adjacents[maxn];

vector<uint32_t> sets[maxn];
uint32_t setIndex[maxn];
uint32_t diameter[maxn];
uint32_t v[maxn];

constexpr uint32_t CeilDivBy2(uint32_t x)
{
    if (x % 2 == 0)
        return x / 2;
    else
        return x / 2 + 1;
}

void InitComponent(uint32_t component, uint32_t vertex, uint32_t parent = 0)
{
    setIndex[vertex] = component;
    sets[component].push_back(vertex);

    for (uint32_t adjacent : adjacents[vertex])
        if (adjacent != parent)
            InitComponent(component, adjacent, vertex);
}

pair<uint32_t, uint32_t> _GetDiameter(uint32_t vertex, uint32_t parent = 0, uint32_t h = 0)
{
    pair<uint32_t, uint32_t> result = make_pair(h, vertex);

    for (uint32_t adjacent : adjacents[vertex])
        if (adjacent != parent)
            result = max(result, _GetDiameter(adjacent, vertex, h + 1));

    return result;
}

#define GET_DIAMETER(component) _GetDiameter(_GetDiameter(sets[component][0]).second).first

void Union(uint32_t x, uint32_t y)
{
    if (x == y)
        return;

    if (sets[x].size() > sets[y].size())
        swap(x, y);

    diameter[y] = max(
        max(diameter[x], diameter[y]),
        CeilDivBy2(diameter[x]) + CeilDivBy2(diameter[y]) + 1
    );

    for (uint32_t element : sets[x])
    {
        setIndex[element] = y;
        sets[y].push_back(element);
    }
}

int main()
{
    scanf("%u%u%u", &n, &m, &q);
    while (m--)
    {
        uint32_t v, u;
        scanf("%u%u", &v, &u);
        adjacents[v].push_back(u);
        adjacents[u].push_back(v);
    }

    memset(setIndex + 1, 0, n * sizeof(uint32_t));
    uint32_t componentCount = 1;
    for (uint32_t i = 1; i <= n; i++)
    {
        if (setIndex[i] == 0)
        {
            InitComponent(componentCount, i);
            componentCount++;
        }
    }

    for (uint32_t i = 1; i < componentCount; i++)
        diameter[i] = GET_DIAMETER(i);

    while (q--)
    {
        uint32_t o, x, y;
        scanf("%u%u", &o, &x);
        if (o == 1)
            printf("%u\n", diameter[setIndex[x]]);
        else
        {
            scanf("%u", &y);
            Union(setIndex[x], setIndex[y]);
        }
    }

    return (0 ^ 0);
}
