// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

struct STVertex
{
    int64_t maxLength, lCount, rCount;
};

constexpr int64_t maxn = 1000000;
string s;
STVertex tree[4 * maxn];

void Build(int64_t idl = 0, int64_t idr = s.size(), int64_t id = 1)
{
    if (idl + 1 == idr)
    {
        tree[id].maxLength = 0;

        if (s[idl] == '(')
        {
            tree[id].lCount = 1;
            tree[id].rCount = 0;
        }
        else
        {
            tree[id].lCount = 0;
            tree[id].rCount = 1;
        }

        return;
    }

    int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
    Build(idl, mid, lc);
    Build(mid, idr, rc);

    tree[id].maxLength = tree[lc].maxLength + tree[rc].maxLength;
    tree[id].rCount = tree[lc].rCount;
    tree[id].lCount = tree[rc].lCount;

    if (tree[lc].lCount < tree[rc].rCount)
    {
        tree[id].maxLength += tree[lc].lCount;
        tree[id].rCount += tree[rc].rCount - tree[lc].lCount;
    }
    else
    {
        tree[id].maxLength += tree[rc].rCount;
        tree[id].lCount += tree[lc].lCount - tree[rc].rCount;
    }
}

vector<int64_t> segments;
void Get(int64_t l, int64_t r, int64_t idl = 0, int64_t idr = s.size(), int64_t id = 1)
{
    if (l >= idr || r <= idl)
        return;
    if (l <= idl && r >= idr)
    {
        segments.push_back(id);
        return;
    }

    int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
    Get(l, r, idl, mid, lc);
    Get(l, r, mid, idr, rc);
}

int main()
{
    cin >> s;
    Build();

    int64_t m;
    cin >> m;
    while (m--)
    {
        int64_t l, r;
        cin >> l >> r;
        Get(l - 1, r);

        if (segments.size() == 0)
            cout << "0\n";
        else
        {
            int64_t ans = tree[segments[0]].maxLength;
            int64_t count = tree[segments[0]].lCount;
            for (int64_t i = 1; i < segments.size(); i++)
            {
                const STVertex& v = tree[segments[i]];
                ans += v.maxLength;
                if (count < v.rCount)
                {
                    ans += count;
                    count = 0;
                }
                else
                {
                    ans += v.rCount;
                    count -= v.rCount;
                }

                count += v.lCount;
            }

            cout << 2 * ans << '\n';
            segments.clear();
        }
    }

    return (0 ^ 0);
}
