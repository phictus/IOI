// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdint>
#include <cstdio>
#include <vector>

using namespace std;

constexpr uint32_t maxn = 100001;
constexpr uint32_t maxlogn = 17;
uint32_t n, m;
vector<uint32_t> adjacents[maxn];
uint32_t ancestor[maxn][maxlogn];
uint32_t depth[maxn];
uint32_t startTime[maxn], finishTime[maxn];
uint32_t time = 0;

#define CHILDREN(v) (finishTime[v] - startTime[v] - 1)

void Initialize(uint32_t vertex = 1, uint32_t parent = 0)
{
    startTime[vertex] = time++;
    depth[vertex] = depth[parent] + 1;

    ancestor[vertex][0] = parent;
    for (uint32_t i = 1; i < maxlogn; i++)
        ancestor[vertex][i] = ancestor[ancestor[vertex][i - 1]][i - 1];

    for (uint32_t adjacent : adjacents[vertex])
        if (adjacent != parent)
            Initialize(adjacent, vertex);

    finishTime[vertex] = time;
}

struct LCAResult
{
    uint32_t LCA, X, Y;
};

LCAResult LCA(uint32_t x, uint32_t y)
{
    for (int32_t i = maxlogn - 1; i >= 0; i--)
        if (((depth[x] - depth[y]) >> i) & 1)
            x = ancestor[x][i];

    if (x == y)
        return {x, 0, 0};

    for (int32_t i = maxlogn - 1; i >= 0; i--)
    {
        if (ancestor[x][i] != ancestor[y][i])
        {
            x = ancestor[x][i];
            y = ancestor[y][i];
        }
    }

    return {ancestor[x][0], x, y};
}

uint32_t NumberOfRooms(uint32_t x, uint32_t y)
{
    if (depth[x] < depth[y])
        swap(x, y);

    if ((depth[x] - depth[y]) % 2 == 1)
        return 0;

    LCAResult lca = LCA(x, y);
    if (depth[x] == depth[y])
        return n - CHILDREN(lca.X) - CHILDREN(lca.Y) - 2;
    else
    {
        uint32_t distance = depth[x] + depth[y] - (2 * depth[lca.LCA]);

        distance /= 2;
        distance--;
        for (uint32_t i = 0; distance != 0; i++)
        {
            if (distance & 1)
                x = ancestor[x][i];

            distance /= 2;
        }

        return CHILDREN(ancestor[x][0]) - CHILDREN(x);
    }
}

int main()
{
    scanf("%u", &n);
    for (uint32_t i = 1; i < n; i++)
    {
        uint32_t v, u;
        scanf("%u%u", &v, &u);
        adjacents[v].push_back(u);
        adjacents[u].push_back(v);
    }

    depth[0] = 0;
    Initialize();

    scanf("%u", &m);
    for (uint32_t i = 0; i < m; i++)
    {
        uint32_t x, y;
        scanf("%u%u", &x, &y);
        printf("%u\n", NumberOfRooms(x, y));
    }

    return (0 ^ 0);
}
