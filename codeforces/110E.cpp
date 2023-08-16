// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdio>
#include <cstdint>
#include <vector>

using namespace std;
using Pair = pair<uint32_t, bool>;

constexpr uint32_t maxn = 100001;
uint32_t n;
vector<Pair> adjacents[maxn];

uint32_t children[maxn];
uint64_t pathDown[maxn];
uint64_t pathUp[maxn];

bool isLucky(uint64_t value)
{
    while (value != 0)
    {
        if (value % 10 != 4 && value % 10 != 7)
            return false;

        value /= 10;
    }

    return true;
}

void initChildren(uint32_t top, uint32_t parent = 0)
{
    children[top] = 0;

    for (const Pair& adj : adjacents[top])
    {
        if (adj.first != parent)
        {
            initChildren(adj.first, top);
            children[top] += children[adj.first] + 1;
        }
    }
}

void initPathDown(uint32_t top, uint32_t parent = 0)
{
    pathDown[top] = 0;

    for (const Pair& adj : adjacents[top])
    {
        if (adj.first != parent)
        {
            initPathDown(adj.first, top);

            if (adj.second)
                pathDown[top] += children[adj.first] + 1;
            else
                pathDown[top] += pathDown[adj.first];
        }
    }
}

void initPathUp(uint32_t top, uint32_t parent = 0)
{
    for (const Pair& adj : adjacents[top])
    {
        if (adj.first != parent)
        {
            if (adj.second)
                pathUp[adj.first] = n - children[adj.first] - 1;
            else
                pathUp[adj.first] = pathUp[top] + pathDown[top] - pathDown[adj.first];

            initPathUp(adj.first, top);
        }
    }
}

int main()
{
    scanf("%u", &n);
    for (uint32_t i = 1; i < n; i++)
    {
        uint32_t v, u;
        uint64_t w;
        scanf("%u%u%llu", &v, &u, &w);

        const bool state = isLucky(w);
        adjacents[v].push_back(make_pair(u, state));
        adjacents[u].push_back(make_pair(v, state));
    }

    initChildren(1);
    initPathDown(1);
    initPathUp(1);
    pathUp[1] = 0;

    uint64_t result = 0;
    for (uint32_t i = 1; i <= n; i++)
        result += (pathDown[i] + pathUp[i]) * (pathDown[i] + pathUp[i] - 1);
    printf("%llu\n", result);

    return (0 ^ 0);
}
