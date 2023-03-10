// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>

using namespace std;

void makeNotDivisible(const uint32_t& x, uint32_t& y, uint32_t& z)
{
    if (y == 1)
    {
        if (x == 0)
            y++;
        else
        {
            do
                y++;
            while (y % x == 0);
        }
    }

    while (z % y == 0)
        z++;
}

int main()
{
    uint32_t t;
    cin >> t;
    while (t--)
    {
        uint32_t n;
        cin >> n;
        uint32_t a[n];
        for (uint32_t i = 0; i < n; i++)
            cin >> a[i];

        makeNotDivisible(0, a[0], a[1]);
        for (uint32_t i = 1; i < n - 1; i++)
            makeNotDivisible(a[i - 1], a[i], a[i + 1]);

        for (uint32_t i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << endl;
    }

    return (0 ^ 0);
}
