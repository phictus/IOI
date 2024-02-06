// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 200000;
int64_t n, m, a[maxn], mh, pm[maxn], sm[maxn];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    mh = 0;
    for (int64_t i = 0; i < n; i++)
    {
        cin >> a[i];
        mh = max(mh, a[i]);
    }

    pm[0] = a[0];
    for (int64_t i = 1; i < n; i++)
        pm[i] = max(pm[i - 1], a[i]);

    sm[n - 1] = a[n - 1];
    for (int64_t i = n - 2; i >= 0; i--)
        sm[i] = max(sm[i + 1], a[i]);

    int64_t lCount = 0, rCount = 0;
    for (int64_t i = 0; i < m; i++)
    {
        char c;
        cin >> c;
        if (c == 'L')
            lCount++;
        else
            rCount++;
    }

    for (int64_t i = 0; i < n; i++)
        a[i] += min(lCount, pm[i] - a[i]) + min(rCount, sm[i] - a[i]);

    for (int64_t i = 0; i < n; i++)
        cout << min(mh, a[i]) << ' ';
    cout << '\n';

    return (0 ^ 0);
}
