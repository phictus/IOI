// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    int64_t n, mini = 1000000001, maxi = 0;
    cin >> n;
    for (int64_t i = 0; i < n; i++)
    {
        int64_t a;
        cin >> a;
        mini = min(mini, a);
        maxi = max(maxi, a);
    }

    cout << maxi - mini << '\n';
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
