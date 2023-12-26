// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    int64_t n;
    cin >> n;
    bool c1 = true, c2 = true, c3 = true, c4 = true;
    for (int64_t i = 0; i < n; i++)
    {
        int64_t x, y;
        cin >> x >> y;
        if (x > 0)
            c2 = false;
        if (x < 0)
            c1 = false;
        if (y > 0)
            c4 = false;
        if (y < 0)
            c3 = false;
    }

    if (c1 || c2 || c3 || c4)
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
