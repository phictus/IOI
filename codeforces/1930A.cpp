// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 50;
int64_t n, a[2 * maxn];

void SolveTestCase()
{
    cin >> n;
    for (int64_t i = 0; i < 2 * n; i++)
        cin >> a[i];
    sort(a, a + 2 * n);

    int64_t result = 0;
    for (int64_t i = 0; i < 2 * n; i += 2)
        result += a[i];
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
