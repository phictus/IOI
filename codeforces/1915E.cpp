// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <map>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 200002;
int64_t n, dp[maxn];

bool SolveTestCase()
{
    cin >> n;
    for (int64_t i = 2; i < n + 2; i++)
    {
        int64_t a;
        cin >> a;
        dp[i] = dp[i - 2] + a;
    }

    map<int64_t, bool> m[2];
    for (int64_t i = 2; i < n + 2; i++)
    {
        if (m[i % 2][dp[i - 1] - dp[i]] || m[1 - i % 2][dp[i] - dp[i - 1]])
            return true;

        m[i % 2][dp[i - 1] - dp[i - 2]] = true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t testCase;
    cin >> testCase;
    while (testCase--)
    {
        if (SolveTestCase())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return (0 ^ 0);
}
