// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <algorithm>

using namespace std;
using Pair = pair<uint64_t, uint64_t>;

struct Query
{
    uint64_t q, l, r;
};

constexpr uint64_t maxn = 200000, maxsqrtn = 448;
constexpr uint64_t maxa = 1000001;

uint64_t n, q;
uint64_t arr[maxn];
uint64_t numCount[maxa];
Query queries[maxn];
Pair results[maxn];

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

    cin >> n >> q;
    for (uint64_t i = 0; i < n; i++)
        cin >> arr[i];
    for (uint64_t i = 0; i < q; i++)
    {
        queries[i].q = i;
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
    }

    sort(queries, queries + q);
    fill(numCount, numCount + maxa, 0);

    uint64_t l = 0, r = 0, index = 0, ans = 0;
    while (index < q)
    {
        if (r < queries[index].r)
        {
            ans += arr[r] * (2 * numCount[arr[r]] + 1);
            numCount[arr[r]]++;
            r++;
        }
        else if (l > queries[index].l)
        {
            l--;
            ans += arr[l] * (2 * numCount[arr[l]] + 1);
            numCount[arr[l]]++;
        }
        else if (r > queries[index].r)
        {
            r--;
            ans -= arr[r] * (2 * numCount[arr[r]] - 1);
            numCount[arr[r]]--;
        }
        else if (l < queries[index].l)
        {
            ans -= arr[l] * (2 * numCount[arr[l]] - 1);
            numCount[arr[l]]--;
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
