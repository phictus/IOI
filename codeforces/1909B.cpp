// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <set>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100;
int64_t n, a[maxn];

void SolveTestCase()
{
    cin >> n;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];

    for (int64_t i = 2; i <= 200000000000000000; i *= 2)
    {
        set<int64_t> s;
        for (int64_t j = 0; j < n; j++)
            s.insert(a[j] % i);

        if (s.size() == 2)
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
