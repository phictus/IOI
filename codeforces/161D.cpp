// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>

using namespace std;

constexpr uint32_t maxn = 50001, maxk = 501;
uint32_t n, k;
vector<uint32_t> adjacents[maxn];

uint64_t NumberOfPaths(uint32_t vertex = 1, uint32_t parent = 0)
{
    static uint64_t result = 0;
    static uint64_t dp[maxn][maxk];

    dp[vertex][0] = 1;
    for (uint32_t adjacent : adjacents[vertex])
    {
        if (adjacent != parent)
        {
            NumberOfPaths(adjacent, vertex);

            for (uint32_t i = 1; i <= k; i++)
                result += dp[adjacent][i - 1] * dp[vertex][k - i];

            for (uint32_t i = 1; i <= k; i++)
                dp[vertex][i] += dp[adjacent][i - 1];
        }
    }

    return result;
}

int main()
{
    cin >> n >> k;
    for (uint32_t i = 1; i < n; i++)
    {
        uint32_t v, u;
        cin >> v >> u;
        adjacents[v].push_back(u);
        adjacents[u].push_back(v);
    }

    cout << NumberOfPaths() << endl;

    return (0 ^ 0);
}
