// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    string s;
    cin >> s;

    int64_t oneCount = 0;
    vector<int64_t> dp = {0};
    for (char c : s)
    {
        if (c == '1')
            oneCount++;
        dp.push_back(oneCount);
    }

    for (int64_t i = 0; i <= s.size(); i++)
    {
        if (dp[s.size() - i] <= s.size() - oneCount && s.size() - i - dp[s.size() - i] <= oneCount)
        {
            cout << i << '\n';
            return;
        }
    }
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
