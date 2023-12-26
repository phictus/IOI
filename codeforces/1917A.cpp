// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    int64_t n, negetiveCount = 0;
    bool hasZero = false;

    cin >> n;
    for (int64_t i = 0; i < n; i++)
    {
        int64_t a;
        cin >> a;
        if (a < 0)
            negetiveCount++;
        else if (a == 0)
            hasZero = true;
    }

    if (hasZero || negetiveCount % 2 == 1)
        cout << "0\n";
    else
        cout << "1\n1 0\n";
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
