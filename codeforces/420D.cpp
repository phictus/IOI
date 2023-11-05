// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 1000000;
int64_t n, m, a[2 * maxn + 1], tree[8 * maxn];
bool isUsed[maxn + 1];

#define at(x) (maxn + (x))

void Build(int64_t nl = 1, int64_t nr = at(n + 1), int64_t id = 1)
{
    if (nl + 1 == nr)
    {
        if (nl > at(0))
            tree[id] = 1;
        else
            tree[id] = 0;

        return;
    }

    int64_t mid = (nl + nr) / 2;
    Build(nl, mid, 2 * id);
    Build(mid, nr, 2 * id + 1);

    tree[id] = tree[2 * id] + tree[2 * id + 1];
}

void Update(int64_t index, int64_t value, int64_t nl = 1, int64_t nr = at(n + 1), int64_t id = 1)
{
    if (nl + 1 == nr)
    {
        tree[id] = value;
        return;
    }

    int64_t mid = (nl + nr) / 2;
    if (index < mid)
        Update(index, value, nl, mid, 2 * id);
    else
        Update(index, value, mid, nr, 2 * id + 1);

    tree[id] = tree[2 * id] + tree[2 * id + 1];
}

int64_t Query(int64_t index, int64_t nl = 1, int64_t nr = at(n + 1), int64_t id = 1)
{
    if (nl + 1 == nr)
        return nl;

    int64_t mid = (nl + nr) / 2;
    if (index <= tree[2 * id])
        return Query(index, nl, mid, 2 * id);
    else
        return Query(index - tree[2 * id], mid, nr, 2 * id + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    Build();

    bool result = true;
    for (int64_t i = 0; i < m; i++)
    {
        int64_t x, y;
        cin >> x >> y;

        int64_t z = Query(y);

        if (a[z] == 0)
        {
            if (isUsed[x])
                result = false;

            a[z] = x;
            isUsed[x] = true;
        }
        else if (a[z] != x)
            result = false;

        Update(z, 0);
        Update(at(-i), 1);
        a[at(-i)] = x;
    }

    if (result)
    {
        int64_t offset = 1;
        for (int64_t i = 1; i <= n; i++)
        {
            if (a[at(i)] == 0)
            {
                while (isUsed[offset])
                    offset++;
                cout << offset << ' ';
                offset++;
            }
            else
                cout << a[at(i)] << ' ';
        }

        cout << '\n';
    }
    else
        cout << "-1\n";

    return (0 ^ 0);
}
