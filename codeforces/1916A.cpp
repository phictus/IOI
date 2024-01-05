#include <iostream>
#include <cstdint>

using namespace std;

void Solve()
{
    int64_t n, k, mul = 1;
    cin >> n >> k;
    for (int64_t i = 0; i < n; i++)
    {
        int64_t b;
        cin >> b;
        mul *= b;
    }

    if (2023 % mul != 0)
    {
        cout << "NO\n";
        return;
    }
    else
    {
        cout << "YES\n";
        cout << 2023 / mul << ' ';
        for (int64_t i = 1; i < k; i++)
            cout << "1 ";
        cout << '\n';
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
