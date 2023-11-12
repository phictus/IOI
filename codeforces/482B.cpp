// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

struct STNode
{
    int64_t value = 0, lazy = 0;
};

struct Query
{
    int64_t l, r, q;
};

constexpr int64_t maxn = 100000;
int64_t n, m;
Query query[maxn];
STNode tree[4 * maxn];

void SpreadLazy(int64_t id)
{
    tree[2 * id].value |= tree[id].lazy;
    tree[2 * id].lazy |= tree[id].lazy;

    tree[2 * id + 1].value |= tree[id].lazy;
    tree[2 * id + 1].lazy |= tree[id].lazy;

    tree[id].lazy = 0;
}

void Update(int64_t l, int64_t r, int64_t value, int64_t nl = 0, int64_t nr = n, int64_t id = 1)
{
    if (l >= nr || r <= nl)
        return;
    if (l <= nl && r >= nr)
    {
        tree[id].value |= value;
        tree[id].lazy |= value;
        return;
    }

    int64_t mid = (nl + nr) / 2;
    SpreadLazy(id);

    Update(l, r, value, nl, mid, 2 * id);
    Update(l, r, value, mid, nr, 2 * id + 1);
    tree[id].value = tree[2 * id].value & tree[2 * id + 1].value;
}

int64_t Get(int64_t l, int64_t r, int64_t nl = 0, int64_t nr = n, int64_t id = 1)
{
    if (l >= nr || r <= nl)
        return (1 << 30) - 1;
    if (l <= nl && r >= nr)
        return tree[id].value;

    int64_t mid = (nl + nr) / 2;
    SpreadLazy(id);

    return Get(l, r, nl, mid, 2 * id) & Get(l, r, mid, nr, 2 * id + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int64_t i = 0; i < m; i++)
    {
        cin >> query[i].l >> query[i].r >> query[i].q;
        query[i].l--;

        Update(query[i].l, query[i].r, query[i].q);
    }

    for (int64_t i = 0; i < m; i++)
    {
        if (Get(query[i].l, query[i].r) != query[i].q)
        {
            cout << "NO\n";
            return (0 ^ 0);
        }
    }

    cout << "YES\n";
    for (int64_t i = 0; i < n; i++)
        cout << Get(i, i + 1) << ' ';
    cout << '\n';

    return (0 ^ 0);
}
