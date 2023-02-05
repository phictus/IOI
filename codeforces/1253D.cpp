// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr uint32_t maxn = 200001;
uint32_t n, m;
vector<uint32_t> graph[maxn];
bool graphVisitMark[maxn];

void dfs(uint32_t v, uint32_t& minimum, uint32_t& maximum)
{
    graphVisitMark[v] = true;
    minimum = min(minimum, v);
    maximum = max(maximum, v);

    for (uint32_t e : graph[v])
        if (!graphVisitMark[e])
            dfs(e, minimum, maximum);
}

int main()
{
    cin >> n >> m;

    for (uint32_t i = 0; i < m; i++)
    {
        uint32_t u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(graphVisitMark, 0, maxn);

    vector<pair<uint32_t, uint32_t>> componentMinMax;
    for (uint32_t i = 1; i <= n; i++)
    {
        if (!graphVisitMark[i])
        {
            uint32_t minimum = i, maximum = i;
            dfs(i, minimum, maximum);
            componentMinMax.push_back(make_pair(minimum, maximum));
        }
    }
    sort(componentMinMax.begin(), componentMinMax.end());

    uint32_t ans = 0;
    uint32_t minimum = componentMinMax[0].first, maximum = componentMinMax[0].second;
    for(auto e = componentMinMax.begin() + 1; e < componentMinMax.end(); e++)
    {
        if (e->first >= minimum && e->first <= maximum)
        {
            maximum = max(maximum, e->second);
            ans++;
        }
        else
        {
            minimum = e->first;
            maximum = e->second;
        }
    }
    cout << ans << endl;

    return (0 ^ 0);
}
