// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdio>
#include <cstdint>
#include <vector>

using namespace std;

struct DFSEntity
{
    uint32_t Vertex, Weight;
};

constexpr uint32_t maxn = 100001;
uint32_t n;
vector<DFSEntity> graph[maxn];

uint32_t DFS(uint32_t vertex, uint32_t parent)
{
    uint32_t result = 0;
    for (const DFSEntity& e : graph[vertex])
        if (e.Vertex != parent)
            result = max(result, DFS(e.Vertex, vertex) + e.Weight);

    return result;
}

int main()
{
    scanf("%u", &n);
    uint32_t sumOfWeights = 0;
    for (uint32_t i = 1; i < n; i++)
    {
        uint32_t u, v, w;
        scanf("%u%u%u", &u, &v, &w);
        sumOfWeights += w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    printf("%u\n", 2 * sumOfWeights - DFS(1, 0));

    return (0 ^ 0);
}
