// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr uint32_t maxn = 100001;
constexpr uint32_t maxlogn = 17;
vector<uint32_t> children[maxn];
vector<uint32_t> timesAtHeight[maxn];
uint32_t height[maxn];
uint32_t parent[maxn];
uint32_t ancestor[maxn][maxlogn];
uint32_t beginTime[maxn];
uint32_t endTime[maxn];
uint32_t currentTime = 0;

void DFS(uint32_t v, uint32_t h = 0)
{
    timesAtHeight[h].push_back(currentTime);
    height[v] = h;

    beginTime[v] = currentTime++;

    ancestor[v][0] = parent[v];
    for (uint32_t i = 1; i < maxlogn; i++)
        ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];

    for (uint32_t child : children[v])
        DFS(child, h + 1);

    endTime[v] = currentTime++;
}

uint32_t PAncestor(uint32_t v, uint32_t p)
{
    for (uint32_t i = 0; i < maxlogn; i++)
        if (p & (1 << i))
            v = ancestor[v][i];

    return v;
}

uint32_t PCousins(uint32_t v, uint32_t p)
{
    if (height[v] < p)
        return 0;

    const uint32_t pAncestor = PAncestor(v, p);
    const vector<uint32_t>& list = timesAtHeight[height[v]];

    const auto r = upper_bound(list.begin(), list.end(), endTime[pAncestor]);
    const auto l = lower_bound(list.begin(), list.end(), beginTime[pAncestor]);

    return r - l - 1;
}

int main()
{
    uint32_t n;
    cin >> n;
    vector<uint32_t> roots;
    for (uint32_t i = 1; i <= n; i++)
    {
        uint32_t p;
        cin >> p;
        parent[i] = p;
        children[p].push_back(i);

        if (p == 0)
            roots.push_back(i);
    }

    for (uint32_t root : roots)
        DFS(root);

    uint32_t m;
    cin >> m;
    for (uint32_t i = 0; i < m; i++)
    {
        uint32_t v, p;
        cin >> v >> p;
        cout << PCousins(v, p) << endl;
    }

    return (0 ^ 0);
}
