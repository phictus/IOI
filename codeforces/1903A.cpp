// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    int64_t n, k;
    cin >> n >> k;

    int64_t last = 0;
    bool isSorted = true;
    for (int64_t i = 0; i < n; i++)
    {
        int64_t a;
        cin >> a;
        if (a < last)
            isSorted = false;
        last = a;
    }

    if (k > 1)
        cout << "YES\n";
    else if (isSorted)
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
