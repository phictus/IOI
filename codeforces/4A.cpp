// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>

using namespace std;

int main()
{
    uint16_t w;
    cin >> w;

    if (!(w & 1) && w != 2)
        cout << "YES\n";
    else
        cout << "NO\n";

    return (0 ^ 0);
}
