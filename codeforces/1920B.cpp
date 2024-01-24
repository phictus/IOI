// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <limits>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 200000, neginf = numeric_limits<int64_t>::min();
int64_t n, k, x, a[maxn], pSum[maxn];

int64_t GetSum(int64_t l, int64_t r)
{
    if (r < l || r < 0)
        return 0;
    if (l <= 0)
        return pSum[r];

    return pSum[r] - pSum[l - 1];
}

int64_t GetCase(int64_t r)
{
    return GetSum(0, r - x) - GetSum(r - x + 1, r);
}

void SolveTestCase()
{
    cin >> n >> k >> x;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    pSum[0] = a[0];
    for (int64_t i = 1; i < n; i++)
        pSum[i] = pSum[i - 1] + a[i];

    int64_t result = neginf;
    for (int64_t i = 0; i <= k; i++)
        result = max(result, GetCase(n - i - 1));
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
