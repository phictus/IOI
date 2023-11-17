// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <map>
#include <cmath>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;

constexpr int64_t maxn = 200000;
int64_t n, a[maxn];

int64_t Solve()
{
    cin >> n;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];

    int64_t ans = 0;
    map<Pair, int64_t> m;
    for (int64_t i = 0; i < n; i++)
    {
        int64_t x = (a[i] & (-a[i]));
        Pair p;
        p.first = a[i] / x;
        p.second = a[i] - log2(x);

        ans += m[p]++;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
        cout << Solve() << '\n';

    return (0 ^ 0);
}
