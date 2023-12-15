// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <limits>
#include <algorithm>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 200000;
int64_t n, m, x, y, a[maxn - 2];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> x >> y;
    n -= 2;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    int64_t result = numeric_limits<int64_t>::max();
    for (int64_t i = 0; i <= n - m; i++)
        result = min(result, max(x - a[i], (int64_t)0) + max(a[i + m - 1] - y, (int64_t)0));

    cout << result << '\n';

    return (0 ^ 0);
}
