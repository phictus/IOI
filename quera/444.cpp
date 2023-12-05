// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

struct STVertex
{
    int64_t sum = 0, lazyCount = 0, lazyOffset = 0;
};

constexpr int64_t maxn = 200000, mod = 1000000007;
int64_t n, q, a[maxn];
STVertex tree[4 * maxn];

void BuildTree(int64_t idl = 0, int64_t idr = n, int64_t id = 1)
{
    if (idl + 1 == idr)
    {
        tree[id].sum = a[idl];
        return;
    }

    int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
    BuildTree(idl, mid, lc);
    BuildTree(mid, idr, rc);

    tree[id].sum = tree[lc].sum + tree[rc].sum;
    tree[id].sum %= mod;
}

void SpreadLazy(int64_t idl, int64_t idr, int64_t id)
{
    int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;

    tree[lc].sum += tree[id].lazyCount * (((mid - idl) * (mid - idl + 1) / 2) % mod) + tree[id].lazyOffset * (mid - idl);
    tree[lc].sum %= mod;
    tree[lc].lazyCount += tree[id].lazyCount;
    tree[lc].lazyCount %= mod;
    tree[lc].lazyOffset += tree[id].lazyOffset;
    tree[lc].lazyOffset %= mod;

    int64_t delta = (tree[id].lazyCount * (mid - idl)) % mod;
    tree[rc].sum += tree[id].lazyCount * (((idr - mid) * (idr - mid + 1) / 2) % mod) + (tree[id].lazyOffset + delta) * (idr - mid);
    tree[rc].sum %= mod;
    tree[rc].lazyCount += tree[id].lazyCount;
    tree[rc].lazyCount %= mod;
    tree[rc].lazyOffset += tree[id].lazyOffset + delta;
    tree[rc].lazyOffset %= mod;

    tree[id].lazyCount = 0;
    tree[id].lazyOffset = 0;
}

int64_t GetSum(int64_t l, int64_t r, int64_t idl = 0, int64_t idr = n, int64_t id = 1)
{
    if (l >= idr || r <= idl)
        return 0;
    if (l <= idl && r >= idr)
        return tree[id].sum;

    SpreadLazy(idl, idr, id);
    int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;

    return (GetSum(l, r, idl, mid, lc) + GetSum(l, r, mid, idr, rc)) % mod;
}

void GiveCoin(int64_t l, int64_t r, int64_t idl = 0, int64_t idr = n, int64_t id = 1)
{
    if (l >= idr || r <= idl)
        return;
    if (l <= idl && r >= idr)
    {
        tree[id].sum += ((idr - idl) * (idr - idl + 1) / 2) + ((idl - l) * (idr - idl));
        tree[id].sum %= mod;
        tree[id].lazyCount++;
        tree[id].lazyCount %= mod;
        tree[id].lazyOffset += (idl - l);
        tree[id].lazyOffset %= mod;
        return;
    }

    SpreadLazy(idl, idr, id);
    int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;

    GiveCoin(l, r, idl, mid, lc);
    GiveCoin(l, r, mid, idr, rc);
    tree[id].sum = tree[lc].sum + tree[rc].sum;
    tree[id].sum %= mod;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> q;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];

    BuildTree();

    while (q--)
    {
        char type;
        cin >> type >> type >> type;
        int64_t l, r;
        cin >> l >> r;
        l--;

        if (type == 'k')
            cout << GetSum(l, r) << '\n';
        else
            GiveCoin(l, r);
    }

    return (0 ^ 0);
}
