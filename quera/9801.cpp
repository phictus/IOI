// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 200000, maxk = 50;
int64_t n, k, t[maxk][maxk], a[maxn];

class SegmentTree {
public:
    void buildTree(int64_t idl = 0, int64_t idr = n, int64_t id = 1) {
        _reset(id);
        if (idl + 1 == idr) {
            return;
        }

        int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
        buildTree(idl, mid, lc);
        buildTree(mid, idr, rc);
    }

    void pourColor(int64_t l, int64_t r, int64_t c, int64_t idl = 0, int64_t idr = n, int64_t id = 1) {
        if (idl >= r || idr <= l) {
            return;
        }
        if (idl >= l && idr <= r) {
            for (int64_t i = 0; i < k; i++) {
                _data[id][i] = t[_data[id][i]][c];
            }
            return;
        }

        int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
        _spread(id, lc, rc);

        pourColor(l, r, c, idl, mid, lc);
        pourColor(l, r, c, mid, idr, rc);
    }

    int64_t getColor(int64_t index, int64_t idl = 0, int64_t idr = n, int64_t id = 1) {
        if (idl + 1 == idr) {
            return _data[id][a[index]];
        }

        int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
        _spread(id, lc, rc);

        if (index < mid) {
            return getColor(index, idl, mid, lc);
        } else {
            return getColor(index, mid, idr, rc);
        }
    }

private:
    void _reset(int64_t id) {
        for (int64_t i = 0; i < k; i++) {
            _data[id][i] = i;
        }
    }

    void _spread(int64_t id, int64_t lc, int64_t rc) {
        for (int64_t i = 0; i < k; i++) {
            _data[lc][i] = _data[id][_data[lc][i]];
            _data[rc][i] = _data[id][_data[rc][i]];
        }

        _reset(id);
    }

    int64_t _data[4 * maxn][maxk];
} tree;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int64_t i = 0; i < k; i++) {
        for (int64_t j = 0; j < k; j++) {
            cin >> t[i][j];
            t[i][j]--;
        }
    }
    for (int64_t i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    tree.buildTree();
    int64_t q;
    cin >> q;
    while (q--) {
        char type;
        cin >> type;
        if (type == '#') {
            int64_t l, r, c;
            cin >> l >> r >> c;
            tree.pourColor(l - 1, r, c - 1);
        } else {
            int64_t index;
            cin >> index;
            cout << tree.getColor(index - 1) + 1 << '\n';
        }
    }

    return (0 ^ 0);
}
