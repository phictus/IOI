// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

void SolveTestCase()
{
    int64_t n, p, l, t;
    cin >> n >> p >> l >> t;

    int64_t taskCount = ceil(n / 7.0);
    int64_t left = 0, right = n;
    while (left < right)
    {
        int64_t mid = (left + right) / 2;
        if (mid * l + min(2 * mid, taskCount) * t < p)
            left = mid + 1;
        else
            right = mid;
    }

    cout << n - left << '\n';
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
