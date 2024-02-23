// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    int64_t k, x, a;
    cin >> k >> x >> a;

    int64_t y = 0;
    for (int64_t i = 0; i < x; i++)
    {
        if ((y + k - 1) / (k - 1) == 0)
            y += 1;
        else
            y += (y + k - 1) / (k - 1);
        if (y > a)
            break;
    }

    if (k * (a - y) > a)
        cout << "YES\n";
    else
        cout << "NO\n";
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
