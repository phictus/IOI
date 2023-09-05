// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <set>

using namespace std;

constexpr uint64_t maxn = 200001;
uint64_t value[maxn];
uint64_t parent[maxn];
uint64_t findSet(uint64_t v)
{
    if (parent[v] == v)
        return v;

    parent[v] = findSet(parent[v]);
    return parent[v];
}

uint64_t weight, componentCount;
bool addEdge(uint64_t v, uint64_t u, uint64_t w)
{
    if (findSet(v) == findSet(u) || value[u] % w != 0)
        return false;
    else
    {
        weight += w;
        componentCount--;
        parent[findSet(u)] = findSet(v);

        return true;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);

    uint64_t t;
    cin >> t;
    while (t--)
    {
        uint64_t n, p;
        cin >> n >> p;

        set<pair<uint64_t, uint64_t>> entities;
        for (uint64_t i = 0; i < n; i++)
        {
            parent[i] = i;

            cin >> value[i];
            if (value[i] < p)
                entities.insert(make_pair(value[i], i));
        }

        weight = 0;
        componentCount = n;
        while (!entities.empty())
        {
            auto[w, v] = *entities.begin();
            entities.erase(entities.begin());

            for (uint64_t i = v + 1; i < n; i++)
                if (!addEdge(v, i, w))
                    break;
            for (int64_t i = v - 1; i >= 0; i--)
                if (!addEdge(v, i, w))
                    break;
        }

        cout << weight + (componentCount - 1) * p << '\n';
    }

    return (0 ^ 0);
}
