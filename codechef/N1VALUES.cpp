// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    uint64_t t;
    cin >> t;
    while (t--)
    {
        uint64_t n;
        cin >> n;
        cout << "1 ";
        for (uint64_t i = 0; i < n; i++)
            cout << (1ull << i) << ' ';
        cout << '\n';
    }

    return (0 ^ 0);
}
