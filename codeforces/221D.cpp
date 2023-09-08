// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
using Pair = pair<uint64_t, uint64_t>;

struct Query
{
    uint64_t q, l, r;
};

constexpr uint64_t maxn = 100000, maxsqrtn = 317;

uint64_t a[maxn];
Query queries[maxn];
Pair results[maxn];
unordered_map<uint64_t, uint64_t> numCount;

bool operator<(const Query& v1, const Query& v2)
{
    if (v1.l / maxsqrtn == v2.l / maxsqrtn)
        return v1.r < v2.r;
    else
        return v1.l < v2.l;
}

int main()
{
    ios_base::sync_with_stdio(false);

    uint64_t n, q;
    cin >> n >> q;
    for (uint64_t i = 0; i < n; i++)
        cin >> a[i];

    for (uint64_t i = 0; i < q; i++)
    {
        queries[i].q = i;
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
    }

    sort(queries, queries + q);

    uint64_t l = 0, r = 0, index = 0, ans = 0;
    while (index < q)
    {
        if (r < queries[index].r)
        {
            if (numCount[a[r]] == a[r])
                ans--;

            numCount[a[r]]++;
            if (numCount[a[r]] == a[r])
                ans++;
            r++;
        }
        else if (l > queries[index].l)
        {
            l--;
            if (numCount[a[l]] == a[l])
                ans--;

            numCount[a[l]]++;
            if (numCount[a[l]] == a[l])
                ans++;
        }
        else if (r > queries[index].r)
        {
            r--;
            if (numCount[a[r]] == a[r])
                ans--;

            numCount[a[r]]--;
            if (numCount[a[r]] == a[r])
                ans++;
        }
        else if (l < queries[index].l)
        {
            if (numCount[a[l]] == a[l])
                ans--;

            numCount[a[l]]--;
            l++;
        }
        else
        {
            results[index].first = queries[index].q;
            results[index].second = ans;
            index++;
        }
    }

    sort(results, results + q);
    for (uint64_t i = 0; i < q; i++)
        cout << results[i].second << '\n';

    return (0 ^ 0);
}
