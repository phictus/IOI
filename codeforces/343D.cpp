// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 500000;
int64_t n, q, st[maxn + 1], ft[maxn + 1];
vector<int64_t> adj[maxn + 1];
int64_t tree1[4 * maxn], tree2[4 * maxn];

int64_t t = 0;
void InitDiscovery(int64_t v = 1, int64_t p = 1)
{
    st[v] = t++;

    for (int64_t u : adj[v])
    {
        if (u != p)
            InitDiscovery(u, v);
    }

    ft[v] = t;
}

void InitTrees()
{
    for (int64_t i = 0; i < 4 * n; i++)
    {
        tree1[i] = 0;
        tree2[i] = 0;
    }
}

void Update1(int64_t l, int64_t r, int64_t val, int64_t nl = 0, int64_t nr = n, int64_t id = 1)
{
    if (l >= nr || r <= nl)
        return;
    if (l <= nl && r >= nr)
    {
        tree1[id] = val;
        return;
    }

    int64_t mid = (nl + nr) / 2;
    Update1(l, r, val, nl, mid, 2 * id);
    Update1(l, r, val, mid, nr, 2 * id + 1);
}

int64_t Query1(int64_t index, int64_t nl = 0, int64_t nr = n, int64_t id = 1)
{
    if (nl + 1 == nr)
        return tree1[id];

    int64_t mid = (nl + nr) / 2;
    if (index < mid)
        return max(tree1[id], Query1(index, nl, mid, 2 * id));
    else
        return max(tree1[id], Query1(index, mid, nr, 2 * id + 1));
}

void Update2(int64_t index, int64_t val, int64_t nl = 0, int64_t nr = n, int64_t id = 1)
{
    if (nl + 1 == nr)
    {
        tree2[id] = val;
        return;
    }

    int64_t mid = (nl + nr) / 2;
    if (index < mid)
        Update2(index, val, nl, mid, 2 * id);
    else
        Update2(index, val, mid, nr, 2 * id + 1);

    tree2[id] = max(tree2[2 * id], tree2[2 * id + 1]);
}

int64_t Query2(int64_t l, int64_t r, int64_t nl = 0, int64_t nr = n, int64_t id = 1)
{
    if (l >= nr || r <= nl)
        return 0;
    if (l <= nl && r >= nr)
        return tree2[id];

    int64_t mid = (nl + nr) / 2;
    return max(Query2(l, r, nl, mid, 2 * id), Query2(l, r, mid, nr, 2 * id + 1));
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int64_t i = 1; i < n; i++)
    {
        int64_t v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    InitDiscovery();
    InitTrees();

    cin >> q;
    for (int64_t i = 1; i <= q; i++)
    {
        int64_t type, v;
        cin >> type >> v;
        if (type == 1)
            Update1(st[v], ft[v], i);
        else if (type == 2)
            Update2(st[v], i);
        else
        {
            if (Query1(st[v]) > Query2(st[v], ft[v]))
                cout << "1\n";
            else
                cout << "0\n";
        }
    }

    return (0 ^ 0);
}
