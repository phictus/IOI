// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 200000;
int64_t n, m, capacity[maxn], tree[4 * maxn];

void Build(int64_t idl = 0, int64_t idr = n, int64_t id = 1)
{
    if (idl + 1 == idr)
    {
        tree[id] = capacity[idl];
        return;
    }

    int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
    Build(idl, mid, lc);
    Build(mid, idr, rc);
    tree[id] = max(tree[lc], tree[rc]);
}

int64_t ChooseRoom(int64_t count, int64_t idl = 0, int64_t idr = n, int64_t id = 1)
{
    if (idl + 1 == idr)
    {
        if (tree[id] < count)
            return -1;

        tree[id] -= count;
        return idl;
    }

    int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
    int64_t result = tree[lc] >= count ? ChooseRoom(count, idl, mid, lc) : ChooseRoom(count, mid, idr, rc);

    tree[id] = max(tree[lc], tree[rc]);
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int64_t i = 0; i < n; i++)
        cin >> capacity[i];

    Build();

    for (int64_t i = 0; i < m; i++)
    {
        int64_t count;
        cin >> count;
        cout << ChooseRoom(count) + 1 << '\n';
    }

    return (0 ^ 0);
}
