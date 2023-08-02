// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

constexpr uint32_t maxn = 100001;
constexpr uint32_t maxlogn = 17;

uint32_t n, m, q;
vector<uint32_t> adjacents[maxn];
vector<uint32_t> citizens[maxn];

uint32_t depth[maxn];
uint32_t ancestor[maxn][maxlogn];
vector<uint32_t> min10[maxn][maxlogn];

vector<uint32_t> Merge(vector<uint32_t>& vec1, vector<uint32_t>& vec2)
{
    vector<uint32_t> result;

    auto it1 = vec1.begin();
    auto it2 = vec2.begin();

    while (it1 != vec1.end() && it2 != vec2.end())
    {
        if (result.size() == 10)
            return result;

        if (*it1 < *it2)
        {
            result.push_back(*it1);
            it1++;
        }
        else
        {
            result.push_back(*it2);
            it2++;
        }
    }

    while (it1 != vec1.end())
    {
        if (result.size() == 10)
            return result;

        result.push_back(*it1);
        it1++;
    }

    while (it2 != vec2.end())
    {
        if (result.size() == 10)
            return result;

        result.push_back(*it2);
        it2++;
    }

    return result;
}

void Initialize(uint32_t vertex = 1, uint32_t parent = 0, uint32_t d = 0)
{
    depth[vertex] = d;

    ancestor[vertex][0] = parent;
    for (uint32_t i = 1; i < maxlogn; i++)
        ancestor[vertex][i] = ancestor[ancestor[vertex][i - 1]][i - 1];

    for (uint32_t i = 0; i < citizens[vertex].size() && i < 10; i++)
        min10[vertex][0].push_back(citizens[vertex][i]);
    for (uint32_t i = 1; i < maxlogn; i++)
        min10[vertex][i] = Merge(min10[vertex][i - 1], min10[ancestor[vertex][i - 1]][i - 1]);

    for (uint32_t adjacent : adjacents[vertex])
        if (adjacent != parent)
            Initialize(adjacent, vertex, d + 1);
}

void PrintCitizensOnPath(uint32_t v, uint32_t u, uint32_t a)
{
    vector<uint32_t> result;

    if (depth[v] < depth[u])
        swap(v, u);

    for (int32_t i = maxlogn - 1; i >= 0; i--)
    {
        if (((depth[v] - depth[u]) >> i) & 1)
        {
            result = Merge(result, min10[v][i]);
            v = ancestor[v][i];
        }
    }

    if (v != u)
    {
        for (int32_t i = maxlogn - 1; i >= 0; i--)
        {
            if (ancestor[v][i] != ancestor[u][i])
            {
                result = Merge(result, min10[v][i]);
                result = Merge(result, min10[u][i]);
                v = ancestor[v][i];
                u = ancestor[u][i];
            }
        }

        result = Merge(result, citizens[v]);
        result = Merge(result, citizens[u]);
        result = Merge(result, citizens[ancestor[v][0]]);
    }
    else
        result = Merge(result, citizens[v]);

    uint32_t size = min((uint32_t)result.size(), a);
    cout << size << ' ';
    for (uint32_t i = 0; i < size; i++)
        cout << result[i] << ' ';
    cout << endl;
}

int main()
{
    cin >> n >> m >> q;
    for (uint32_t i = 1; i < n; i++)
    {
        uint32_t v, u;
        cin >> v >> u;
        adjacents[v].push_back(u);
        adjacents[u].push_back(v);
    }
    for (uint32_t i = 1; i <= m; i++)
    {
        uint32_t city;
        cin >> city;
        citizens[city].push_back(i);
    }

    Initialize();

    while (q--)
    {
        uint32_t v, u, a;
        cin >> v >> u >> a;
        PrintCitizensOnPath(v, u, a);
    }

    return (0 ^ 0);
}
