// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100000;
int64_t n, c[maxn];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int64_t i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c + n);

    int64_t ans1 = 0, ans2 = 0;
    for (int64_t i = 0; i < n; i++)
    {
        if (ans1 < c[i] * (n - i))
        {
            ans1 = c[i] * (n - i);
            ans2 = c[i];
        }
        else if (ans1 == c[i] * (n - i) && ans2 > c[i])
        {
            ans1 = c[i] * (n - i);
            ans2 = c[i];
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';

    return (0 ^ 0);
}
