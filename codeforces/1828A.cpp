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
        for (uint32_t i = 1; i <= n; i++)
            cout << 2 * i << ' ';
        cout << endl;
    }

    return (0 ^ 0);
}
