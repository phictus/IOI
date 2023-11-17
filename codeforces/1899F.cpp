// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

void Solve()
{
    int64_t n, q;
    cin >> n >> q;

    for (int64_t i = 1; i < n; i++)
        cout << i << ' ' << i + 1 << '\n';

    int64_t current = n - 1;
    while (q--)
    {
        int64_t dist;
        cin >> dist;

        if (current == dist)
            cout << "-1 -1 -1\n";
        else
        {
            cout << n << ' ' << current << ' ' << dist << '\n';
            current = dist;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
        Solve();

    return (0 ^ 0);
}
