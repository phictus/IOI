// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 150000;
int64_t n, a[maxn], pSum[maxn];

#define Sum(l, r) (pSum[(r - 1)] - pSum[(l) - 1])

int64_t Solve()
{
    cin >> n;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];

    pSum[0] = a[0];
    for (int64_t i = 1; i < n; i++)
        pSum[i] = pSum[i - 1] + a[i];

    int64_t ans = 0;
    for (int64_t i = 1; i < n; i++)
    {
        if (n % i != 0)
            continue;

        int64_t minimum = Sum(0, i), maximum = Sum(0, i);
        for (int64_t j = i; j < n; j += i)
        {
            minimum = min(minimum, Sum(j, j + i));
            maximum = max(maximum, Sum(j, j + i));
        }

        ans = max(ans, maximum - minimum);
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

    return 0;
}
