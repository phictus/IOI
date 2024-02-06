// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 200000;
int64_t n, x, a[maxn], dp[2][maxn];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> x;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];

    vector<int64_t> v;
    for (int64_t i = 0; i < n; i++)
    {
        int64_t index = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        if (index == v.size())
            v.push_back(a[i]);
        else
            v[index] = a[i];

        dp[0][i] = index + 1;
    }

    v.clear();
    for (int64_t i = n - 1; i >= 0; i--)
    {
        dp[1][i] = lower_bound(v.begin(), v.end(), -a[i] + x) - v.begin() + 1;

        auto it = lower_bound(v.begin(), v.end(), -a[i]);
        if (it == v.end())
            v.push_back(-a[i]);
        else
            *it = -a[i];
    }

    int64_t result = 0;
    for (int64_t i = 0; i < n; i++)
        result = max(result, dp[0][i] + dp[1][i] - 1);
    cout << result << '\n';

    return (0 ^ 0);
}
