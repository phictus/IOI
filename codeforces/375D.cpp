// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int32_t maxn = 100001, maxsqrtn = 317;

struct Query
{
    int32_t q, k, l, r;

    bool operator<(const Query& other)
    {
        if (l / maxsqrtn == other.l / maxsqrtn)
            return r < other.r;
        else
            return l < other.l;
    }
};

int32_t n, q;
int32_t tempColor[maxn];
vector<int32_t> adjacents[maxn];
Query queries[maxn];

int32_t color[maxn];
int32_t startTime[maxn];
int32_t finishTime[maxn];

int32_t colorCount[maxn];
int32_t atLeast[maxn];
int32_t results[maxn];

int32_t t = 0;
void init(int32_t v = 1, int32_t p = 0)
{
    t++;
    startTime[v] = t;
    color[startTime[v]] = tempColor[v];

    for (int32_t adj : adjacents[v])
        if (adj != p)
            init(adj, v);

    finishTime[v] = t;
}

void insert(int32_t v)
{
    colorCount[color[v]]++;
    atLeast[colorCount[color[v]]]++;
}

void erase(int32_t v)
{
    atLeast[colorCount[color[v]]]--;
    colorCount[color[v]]--;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> q;
    for (int32_t i = 1; i <= n; i++)
        cin >> tempColor[i];
    for (int32_t i = 1; i < n; i++)
    {
        int32_t v, u;
        cin >> v >> u;
        adjacents[v].push_back(u);
        adjacents[u].push_back(v);
    }

    init();
    for (int32_t i = 0; i < q; i++)
    {
        queries[i].q = i;

        int32_t v;
        cin >> v >> queries[i].k;
        queries[i].l = startTime[v];
        queries[i].r = finishTime[v];
    }

    sort(queries, queries + q);
    fill(colorCount, colorCount + n + 1, 0);
    fill(atLeast, atLeast + n + 1, 0);

    int32_t l = 1, r = 0, index = 0;
    for (int32_t i = 0; i < q; i++)
    {
        while (r < queries[i].r)
            insert(++r);
        while (l > queries[i].l)
            insert(--l);
        while (r > queries[i].r)
            erase(r--);
        while (l < queries[i].l)
            erase(l++);

        results[queries[i].q] = atLeast[queries[i].k];
    }

    for (int32_t i = 0; i < q; i++)
        cout << results[i] << '\n';

    return (0 ^ 0);
}
