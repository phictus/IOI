// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>

using namespace std;

int main()
{
    uint32_t t;
    cin >> t;
    while (t--)
    {
        uint32_t n, m, k;
        cin >> n >> m >> k;
        uint32_t x, y;
        cin >> x >> y;

        const uint32_t r = (x + y) % 2;
        bool result = true;
        for (uint32_t i = 0; i < k; i++)
        {
            uint32_t a, b;
            cin >> a >> b;
            if ((a + b) % 2 == r)
                result = false;
        }

        if (result)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return (0 ^ 0);
}
