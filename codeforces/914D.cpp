// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 500000;
int64_t n, q, a[maxn], tree[4 * maxn];

int64_t Gcd(int64_t x, int64_t y)
{
    if (x > y)
        swap(x, y);
    if (x == 0)
        return y;

    return Gcd(y % x, x);
}

void Build(int64_t idl = 0, int64_t idr = n, int64_t id = 1)
{
    if (idl + 1 == idr)
    {
        tree[id] = a[idl];
        return;
    }

    int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
    Build(idl, mid, lc);
    Build(mid, idr, rc);

    tree[id] = Gcd(tree[lc], tree[rc]);
}

void Update(int64_t index, int64_t value, int64_t idl = 0, int64_t idr = n, int64_t id = 1)
{
    if (idl + 1 == idr)
    {
        tree[id] = value;
        return;
    }

    int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
    if (index < mid)
        Update(index, value, idl, mid, lc);
    else
        Update(index, value, mid, idr, rc);

    tree[id] = Gcd(tree[lc], tree[rc]);
}

int64_t result;
void Get(int64_t l, int64_t r, int64_t value, int64_t idl = 0, int64_t idr = n, int64_t id = 1)
{
    if (result >= 2)
        return;

    if (idl + 1 == idr)
    {
        result++;
        return;
    }

    int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
    if (l < mid && tree[lc] % value != 0)
        Get(l, r, value, idl, mid, lc);
    if (r > mid && tree[rc] % value != 0)
        Get(l, r, value, mid, idr, rc);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];

    Build();

    cin >> q;
    while (q--)
    {
        int64_t type;
        cin >> type;
        if (type == 1)
        {
            int64_t l, r, x;
            cin >> l >> r >> x;
            l--;

            result = 0;
            Get(l, r, x);

            if (result <= 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            int64_t i, y;
            cin >> i >> y;
            i--;

            Update(i, y);
        }
    }

    return (0 ^ 0);
}
