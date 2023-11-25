// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t n, x, a[3] = {0, 0, 0};
    cin >> n;
    for (int64_t i = 0; i < 3 * n; i++)
    {
        cin >> x;
        a[i % 3] += x;
    }

    if (a[0] == 0 && a[1] == 0 && a[2] == 0)
        cout << "YES\n";
    else
        cout << "NO\n";

    return (0 ^ 0);
}
