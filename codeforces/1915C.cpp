// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

bool SolveTestCase()
{
    int64_t n, sum = 0;
    cin >> n;
    for (int64_t i = 0; i < n; i++)
    {
        int64_t a;
        cin >> a;
        sum += a;
    }

    for (int64_t i = 0; i * i != sum; i++)
    {
        if (i * i > sum)
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t testCase;
    cin >> testCase;
    while (testCase--)
    {
        if (SolveTestCase())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return (0 ^ 0);
}
