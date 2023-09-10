// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    uint32_t q;
    cin >> q;
    while (q--)
    {
        uint32_t n, a;
        cin >> n;
        for (uint32_t i = 0; i < n; i++)
            cin >> a;

        if (n % 2 == 0)
        {
            cout << 2 << '\n';
            cout << 1 << ' ' << n << '\n';
            cout << 1 << ' ' << n << '\n';
        }
        else
        {
            cout << 4 << '\n';
            cout << 1 << ' ' << n - 1 << '\n';
            cout << 1 << ' ' << n - 1 << '\n';
            cout << n - 1 << ' ' << n << '\n';
            cout << n - 1 << ' ' << n << '\n';
        }
    }

    return (0 ^ 0);
}
