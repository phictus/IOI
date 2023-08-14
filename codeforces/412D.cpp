// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <vector>

using namespace std;

constexpr uint32_t maxn = 30001;
uint32_t n, m;
vector<uint32_t> adjacents[maxn];
bool isVisited[maxn];

void DFS(uint32_t vertex)
{
    isVisited[vertex] = true;

    for (uint32_t adj : adjacents[vertex])
        if (!isVisited[adj])
            DFS(adj);

    printf("%u\n", vertex);
}

int main()
{
    scanf("%u%u", &n, &m);
    for (uint32_t i = 0; i < m; i++)
    {
        uint32_t v, u;
        scanf("%u%u", &v, &u);
        adjacents[v].push_back(u);
    }

    memset(isVisited, 0, (n + 1) * sizeof(bool));
    for (uint32_t i = 1; i <= n; i++)
        if (!isVisited[i])
            DFS(i);

    return (0 ^ 0);
}
