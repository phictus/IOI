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
        uint32_t n, m;
        cin >> n >> m;

        if (m == 1)
            cout << 0 << '\n';
        else
            cout << min(n + 1, m) << '\n';

        for (uint32_t i = 0; i < n; i++)
        {
            for (uint32_t j = 0; j < m; j++)
            {
                if (i < m - 1)
                    cout << (i + j) % m << ' ';
                else
                    cout << j << ' ';
            }

            cout << '\n';
        }
    }

    return (0 ^ 0);
}
