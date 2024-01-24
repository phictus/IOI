// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 200000;
int64_t n, a[maxn];

int64_t Gcd(int64_t x, int64_t y)
{
    if (x > y)
        swap(x, y);
    if (x == 0)
        return y;

    return Gcd(y % x, x);
}

void SolveTestCase()
{
    cin >> n;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];

    int64_t result = 0;
    for (int64_t k = 1; k <= n; k++)
    {
        if (n % k != 0)
            continue;

        int64_t gcd = 0;
        for (int64_t i = 0; i < k; i++)
        {
            for (int64_t j = i + k; j < n; j += k)
                gcd = Gcd(gcd, abs(a[j] - a[j - k]));
        }

        if (gcd != 1)
            result++;
    }

    cout << result << '\n';
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
