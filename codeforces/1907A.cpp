// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    char c;
    int64_t n;
    cin >> c >> n;
    for (int64_t k = 1; k <= 8; k++)
    {
        if (k == n)
            continue;
        cout << c << k << '\n';
    }
    for (char k = 'a'; k <= 'h'; k++)
    {
        if (k == c)
            continue;
        cout << k << n << '\n';
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
