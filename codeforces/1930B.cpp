// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    int64_t n;
    cin >> n;
    if (n % 2 == 0)
    {
        for (int64_t i = 1; i <= n / 2; i++)
        {
            cout << i << ' ';
            cout << i + n / 2 << ' ';
        }
    }
    else
    {
        for (int64_t i = 1; i <= n / 2; i++)
        {
            cout << i << ' ';
            cout << i + (n + 1) / 2 << ' ';
        }
        cout << (n + 1) / 2 << ' ';
    }

    cout << '\n';
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
