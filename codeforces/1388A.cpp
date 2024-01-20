// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    int64_t n;
    cin >> n;
    if (n <= 30)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        if (n == 36 || n == 40 || n == 44)
            cout << "6 10 15 " << n - 31 << '\n';
        else
            cout << "6 10 14 " << n - 30 << '\n';
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
