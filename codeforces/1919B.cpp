// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

void SolveTestCase()
{
    int64_t n, cnt[2] = {0, 0};
    cin >> n;
    for (int64_t i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == '-')
            cnt[0]++;
        else
            cnt[1]++;
    }

    cout << abs(cnt[0] - cnt[1]) << '\n';
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
