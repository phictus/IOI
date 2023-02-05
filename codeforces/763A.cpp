// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>

using namespace std;

constexpr uint32_t maxn = 100001;
uint32_t n;
vector<uint32_t> graph[maxn];
uint32_t color[maxn];

bool dfs(uint32_t v, uint32_t parent)
{
    for (uint32_t e : graph[v])
    {
        if (e != parent)
        {
            if (color[v] != color[e])
                return false;
            if (!dfs(e, v))
                return false;
        }
    }

    return true;
}

int main()
{
    cin >> n;
    for (uint32_t i = 1; i < n; i++)
    {
        uint32_t u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (uint32_t i = 1; i <= n; i++)
        cin >> color[i];

    uint32_t possibleNode1, possibleNode2;
    for (uint32_t i = 1; i <= n; i++)
        for (uint32_t e : graph[i])
            if (color[e] != color[i])
            {
                possibleNode1 = i;
                possibleNode2 = e;
                goto LABEL0;
            }

    cout << "YES\n" << "1" << endl;
    return (0 ^ 0);

LABEL0:
    for (uint32_t e : graph[possibleNode1])
        if (!dfs(e, possibleNode1))
            goto LABEL1;

    cout << "YES\n" << possibleNode1 << endl;\
    return (0 ^ 0);

LABEL1:
    for(uint32_t e : graph[possibleNode2])
        if(!dfs(e, possibleNode2))
        {
            cout << "NO" << endl;
            return (0 ^ 0);
        }

    cout << "YES\n" << possibleNode2 << endl;
    return (0 ^ 0);
}
