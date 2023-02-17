// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    uint32_t t;
    cin >> t;
    while (t--)
    {
        uint32_t n, u;
        cin >> n >> u;
        int64_t a[n + 1];
        memset(a, 0, (n + 1) * sizeof(int64_t));
        for (uint32_t i = 0; i < u; i++)
        {
            uint32_t l, r, val;
            cin >> l >> r >> val;
            a[l] += val;
            a[r + 1] -= val;
        }

        int64_t x = 0;
        for (uint32_t i = 0; i < n; i++)
        {
            x += a[i];
            a[i] = x;
        }

        uint32_t q;
        cin >> q;
        while (q--)
        {
            uint32_t index;
            cin >> index;
            cout << a[index] << endl;
        }
    }

    return (0 ^ 0);
}
