// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>

using namespace std;

constexpr uint64_t maxn = 100001;
vector<uint64_t> graph[maxn];
int64_t value[maxn];

pair<int64_t, int64_t> DFS(uint64_t vertex, uint64_t parent)
{
    pair<int64_t, int64_t> result = make_pair(0, 0);

    for (uint64_t adjacent : graph[vertex])
    {
        if (adjacent != parent)
        {
            auto x = DFS(adjacent, vertex);
            result.first = max(result.first, x.first);
            result.second = max(result.second, x.second);
        }
    }

    if (result.first + value[vertex] > result.second)
        result.second = result.first + value[vertex];
    else
        result.first = result.second - value[vertex];

    return result;
}

int main()
{
    uint64_t n;
    cin >> n;
    for (uint64_t i = 1; i < n; i++)
    {
        uint64_t u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (uint64_t i = 1; i <= n; i++)
        cin >> value[i];

    auto result = DFS(1, 0);

    cout << result.first + result.second << endl;

    return (0 ^ 0);
}
