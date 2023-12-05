// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    int64_t n;
    cin >> n;
    int64_t oneCount = 0;
    for (int64_t i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == '1')
            oneCount++;
    }

    if (oneCount == n)
        cout << "NO\n";
    else
        cout << "YES\n";
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
