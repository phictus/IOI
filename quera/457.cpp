// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;

constexpr int64_t maxn = 100000;
int64_t n, q;

struct ColorTree
{
    set<Pair> data[4 * maxn];

    void Paint(int64_t t, int64_t l, int64_t r, int64_t c, int64_t idl = 0, int64_t idr = n, int64_t id = 1)
    {
        if (idl >= r || idr <= l)
            return;
        if (idl >= l && idr <= r)
        {
            data[id].insert(make_pair(-t, c));
            return;
        }

        int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
        Paint(t, l, r, c, idl, mid, lc);
        Paint(t, l, r, c, mid, idr, rc);
    }

    Pair GetColor(int64_t t, int64_t index, int64_t idl = 0, int64_t idr = n, int64_t id = 1)
    {
        Pair result;
        auto it = data[id].lower_bound(make_pair(-t, (int64_t)0));
        if (it == data[id].end())
            result = make_pair((int64_t)0, (int64_t)0);
        else
            result = *it;

        if (idl + 1 == idr)
            return result;

        int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
        if (index < mid)
            return min(result, GetColor(t, index, idl, mid, lc));
        else
            return min(result, GetColor(t, index, mid, idr, rc));
    }
} tree;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> q;
    while (q--)
    {
        char type;
        cin >> type;
        if (type == '~')
        {
            int64_t t, l, r, c;
            cin >> t >> l >> r >> c;
            l--;

            tree.Paint(t, l, r, c);
        }
        else
        {
            int64_t t, index;
            cin >> t >> index;
            index--;

            cout << tree.GetColor(t, index).second << '\n';
        }
    }

    return (0 ^ 0);
}
