// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

int64_t dp[100001];

void Init()
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 0;

    for (int64_t i = 3; i <= 100000; i++)
        dp[i] = dp[i - 3] + 1;
}

void SolveTestCase()
{
    int64_t n, sum, oddCount = 0;
    cin >> n >> sum;
    if (sum % 2 == 1)
        oddCount++;
    cout << sum << '\n';
    for (int64_t i = 2; i <= n; i++)
    {
        int64_t a;
        cin >> a;
        sum += a;
        if (a % 2 == 1)
            oddCount++;

        cout << sum - dp[oddCount] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    Init();

    int64_t testCase;
    cin >> testCase;
    while (testCase--)
        SolveTestCase();

    return (0 ^ 0);
}
