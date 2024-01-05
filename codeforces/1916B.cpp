// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

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
    int64_t a, b;
    cin >> a >> b;

    int64_t g = Gcd(a, b);
    if (b % a == 0)
    {
        for (int64_t i = 2; i * i <= b; i++)
        {
            if ((i <= a && a % i == 0) || b % i == 0)
            {
                cout << b * i << '\n';
                return;
            }
        }

        cout << b * b << '\n';
    }
    else
        cout << a * b / g << '\n';
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
