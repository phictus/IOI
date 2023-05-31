// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>

using namespace std;

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

        for (uint32_t i = 0; i < n; i++)
            cout << n - a[i] + 1 << ' ';
        cout << endl;
    }

    return (0 ^ 0);
}
