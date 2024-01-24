// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t a, b;
    cin >> a >> b;
    if (a == b)
        cout << "Saal Noo Mobarak!\n";
    else
    {
        char c = a < b ? 'R' : 'L';
        for (int64_t i = 0; i < abs(a - b); i++)
            cout << c;
        cout << '\n';
    }

    return (0 ^ 0);
}
