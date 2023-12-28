// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    int64_t x = 0;
    for (int64_t i = 0; i < 3; i++)
    {
        int64_t y;
        cin >> y;
        x ^= 1 << y;
    }

    int64_t z = 0;
    while (x != 1)
    {
        x /= 2;
        z++;
    }

    cout << z << '\n';
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
