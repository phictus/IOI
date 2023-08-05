// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstdint>
#include <cstring>

using namespace std;
using Pair = pair<uint32_t, uint32_t>;
using Triple = pair<uint32_t, Pair>;

constexpr uint32_t maxn = 3001;
uint32_t n, m, k;
vector<uint32_t> adjacents[maxn];
map<Triple, bool> restrictions;
uint32_t parent[maxn * maxn];

#define AT(x, y) ((y) + ((x) * maxn))

Pair BFS()
{
    memset(parent, 0, maxn * maxn * sizeof(uint32_t));

    queue<Pair> q;
    q.push(make_pair(0, 1));
    while (!q.empty())
    {
        Pair top = q.front();
        q.pop();

        if (top.second == n)
            return top;

        for (uint32_t adj : adjacents[top.second])
        {
            Triple restriction = make_pair(top.first, make_pair(top.second, adj));
            if (parent[AT(top.second, adj)] == 0 && restrictions.find(restriction) == restrictions.end())
            {
                parent[AT(top.second, adj)] = top.first;
                q.push(make_pair(top.second, adj));
            }
        }
    }

    return make_pair(0, 0);
}

int main()
{
    cin >> n >> m >> k;

    for (uint32_t i = 0; i < m; i++)
    {
        uint32_t v, u;
        cin >> v >> u;
        adjacents[v].push_back(u);
        adjacents[u].push_back(v);
    }

    for (uint32_t i = 0; i < k; i++)
    {
        uint32_t a, b, c;
        cin >> a >> b >> c;
        restrictions[make_pair(a, make_pair(b, c))] = true;
    }

    Pair result = BFS();

    if (result.second == 0)
        cout << -1 << endl;
    else
    {
        vector<uint32_t> path;
        while (result.second != 1)
        {
            path.push_back(result.second);
            result = make_pair(parent[AT(result.first, result.second)], result.first);
        }
        path.push_back(result.second);

        cout << path.size() - 1 << endl;
        for (auto it = path.rbegin(); it != path.rend(); it++)
            cout << *it << ' ';
        cout << endl;
    }

    return 0;
}
