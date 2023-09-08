// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <algorithm>

using namespace std;
using Pair = pair<uint32_t, uint32_t>;

struct Query
{
    uint32_t q, l, r;
};

constexpr uint32_t maxq = 200000, maxsqrtq = 448;
constexpr uint32_t maxn = 30000, maxa = 1000001;

uint32_t a[maxn];
Query queries[maxq];
Pair results[maxq];
uint32_t numCount[maxa];

bool operator<(const Query& v1, const Query& v2)
{
    if (v1.l / maxsqrtq == v2.l / maxsqrtq)
        return v1.r < v2.r;
    else
        return v1.l < v2.l;
}

int main()
{
    ios_base::sync_with_stdio(false);

    uint32_t n;
    cin >> n;
    for (uint32_t i = 0; i < n; i++)
        cin >> a[i];

    uint32_t q;
    cin >> q;
    for (uint32_t i = 0; i < q; i++)
    {
        queries[i].q = i;
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
    }

    sort(queries, queries + q);

    fill(numCount, numCount + maxa, 0);
    numCount[a[0]]++;

    uint32_t l = 0, r = 0, index = 0, distinctCount = 1;
    while (index < q)
    {
        if (r < queries[index].r)
        {
            r++;
            if (numCount[a[r]] == 0)
                distinctCount++;
            numCount[a[r]]++;
        }
        else if (l > queries[index].l)
        {
            l--;
            if (numCount[a[l]] == 0)
                distinctCount++;
            numCount[a[l]]++;
        }
        else if (r > queries[index].r)
        {
            numCount[a[r]]--;
            if (numCount[a[r]] == 0)
                distinctCount--;
            r--;
        }
        else if (l < queries[index].l)
        {
            numCount[a[l]]--;
            if (numCount[a[l]] == 0)
                distinctCount--;
            l++;
        }
        else
        {
            results[index].first = queries[index].q;
            results[index].second = distinctCount;
            index++;
        }
    }

    sort(results, results + q);
    for (uint32_t i = 0; i < q; i++)
        cout << results[i].second << '\n';

    return (0 ^ 0);
}
