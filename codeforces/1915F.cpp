// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <cstdint>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using Pair = pair<int64_t, int64_t>;
using OrderedSet = tree<int64_t, null_type, less<int64_t>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int64_t maxn = 200000;
int64_t n;
Pair a[maxn];

void SolveTestCase()
{
    cin >> n;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);

    int64_t result = 0;
    OrderedSet s;
    for (int64_t i = n - 1; i >= 0; i--)
    {
        result += s.order_of_key(a[i].second);
        s.insert(a[i].second);
    }

    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t testCase;
    cin >> testCase;
    while (testCase--)
        SolveTestCase();

    return (0 ^ 0);
}
