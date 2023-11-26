// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 10;
int64_t n, a[maxn];

bool Solve()
{
    cin >> n;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];

    for (int64_t i = n - 2; i >= 1; i--)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            swap(a[i], a[i + 1]);
            i = n - 1;
        }
    }

    for (int64_t i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
    {
        if (Solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return (0 ^ 0);
}
