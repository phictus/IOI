// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <cstdint>

using namespace std;
using LIPair = pair<uint64_t, uint32_t>;
using LLPair = pair<uint64_t, uint64_t>;

constexpr uint32_t maxn = 1001;
uint32_t n, m;
uint32_t x, y;
vector<LIPair> adjacents[maxn];
LLPair taxi[maxn];

uint64_t dis[maxn][maxn];
uint64_t price[maxn];

void Dijkstra1(uint32_t root)
{
    priority_queue<LIPair, vector<LIPair>, greater<LIPair>> q;
    fill(dis[root] + 1, dis[root] + n + 1, numeric_limits<uint64_t>::max());
    q.push(make_pair(0, root));

    while (!q.empty())
    {
        LIPair top = q.top();
        q.pop();

        if (dis[root][top.second] <= top.first)
            continue;
        dis[root][top.second] = top.first;

        for (const LIPair& adj : adjacents[top.second])
            q.push(make_pair(top.first + adj.first, adj.second));
    }
}

void Dijkstra2()
{
    priority_queue<LIPair, vector<LIPair>, greater<LIPair>> q;
    fill(price + 1, price + n + 1, numeric_limits<uint64_t>::max());
    q.push(make_pair(0, x));

    while (!q.empty())
    {
        LIPair top = q.top();
        q.pop();

        if (price[top.second] <= top.first)
            continue;
        price[top.second] = top.first;

        for (uint32_t i = 1; i <= n; i++)
            if (dis[top.second][i] <= taxi[top.second].first)
                q.push(make_pair(top.first + taxi[top.second].second, i));
    }

}

int main()
{
    cin >> n >> m;
    cin >> x >> y;

    for (uint32_t i = 1; i <= m; i++)
    {
        uint32_t v, u;
        uint64_t w;
        cin >> v >> u >> w;
        adjacents[v].push_back(make_pair(w, u));
        adjacents[u].push_back(make_pair(w, v));
    }

    for (uint32_t i = 1; i <= n; i++)
    {
        uint64_t t, c;
        cin >> t >> c;
        taxi[i] = make_pair(t, c);
    }

    for (uint32_t i = 1; i <= n; i++)
        Dijkstra1(i);
    Dijkstra2();

    if (price[y] == numeric_limits<uint64_t>::max())
        cout << -1 << endl;
    else
        cout << price[y] << endl;

    return (0 ^ 0);
}
