// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 1000000;
int64_t n, in[maxn], a[maxn], b[maxn], tree[4 * maxn];
unordered_map<int64_t, int64_t> cnt;

void Update(int64_t index, int64_t nl = 0, int64_t nr = n, int64_t id = 1)
{
    if (nl + 1 == nr)
    {
        tree[id]++;
        return;
    }

    int64_t mid = (nl + nr) / 2;
    if (index < mid)
        Update(index, nl, mid, 2 * id);
    else
        Update(index, mid, nr, 2 * id + 1);

    tree[id] = tree[2 * id] + tree[2 * id + 1];
}

int64_t Query(int64_t l, int64_t r, int64_t nl = 0, int64_t nr = n, int64_t id = 1)
{
    if (l >= nr || r <= nl)
        return 0;
    if (l <= nl && r >= nr)
        return tree[id];

    int64_t mid = (nl + nr) / 2;
    return Query(l, r, nl, mid, 2 * id) + Query(l, r, mid, nr, 2 * id + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int64_t i = 0; i < n; i++)
        cin >> in[i];

    for (int64_t i = 0; i < n; i++)
    {
        cnt[in[i]]++;
        a[i] = cnt[in[i]];
    }

    cnt.clear();

    for (int64_t i = n - 1; i >= 0; i--)
    {
        cnt[in[i]]++;
        b[i] = cnt[in[i]];
    }


    int64_t result = 0;
    Update(b[n - 1]);
    for (int64_t i = n - 2; i >= 0; i--)
    {
        result += Query(1, a[i]);
        Update(b[i]);
    }

    cout << result << '\n';

    return (0 ^ 0);
}
