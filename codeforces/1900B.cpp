// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

bool Check(int64_t x, int64_t y, int64_t z)
{
    return x % 2 == y % 2;
}

void Solve()
{
    int64_t a, b, c;
    cin >> a >> b >> c;

    int64_t r1 = 0, r2 = 0, r3 = 0;
    if (a % 2 == b % 2)
        r3 = 1;
    if (a % 2 == c % 2)
        r2 = 1;
    if (b % 2 == c % 2)
        r1 = 1;

    cout << r1 << ' ' << r2 << ' ' << r3 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
        Solve();

    return (0 ^ 0);
}
