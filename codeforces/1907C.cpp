// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    int64_t n;
    cin >> n;
    int64_t cnt[26];
    for (int64_t i = 0; i < 26; i++)
        cnt[i] = 0;
    for (int64_t i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        cnt[c - 'a']++;
    }

    int64_t maximum = 0;
    for (int64_t i = 1; i < 26; i++)
    {
        if (cnt[maximum] < cnt[i])
            maximum = i;
    }
    int64_t sum = 0;
    for (int64_t i = 0; i < 26; i++)
    {
        if (i == maximum)
            continue;
        sum += cnt[i];
    }

    if (sum >= cnt[maximum])
        cout << n % 2 << '\n';
    else
        cout << cnt[maximum] - sum << '\n';
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
