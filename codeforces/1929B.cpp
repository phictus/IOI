// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    int64_t n, k;
    cin >> n >> k;
    if (k > 4 * n - 4)
        cout << (2 * n - 2) + k - (4 * n - 4) << '\n';
    else
        cout << (k + 1) / 2 << '\n';
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
