// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    uint32_t q;
    cin >> q;
    while (q--)
    {
        uint32_t n;
        cin >> n;
        pair<uint32_t, uint32_t> a[n];
        for (uint32_t i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a, a + n);
        pair<uint32_t, uint32_t> b[n];
        for (uint32_t i = n; i > 0; i--)
        {
            b[i - 1].first = a[n - i].second;
            b[i - 1].second = i;
        }

        sort(b, b + n);
        for (uint32_t i = 0; i < n; i++)
            cout << b[i].second << ' ';
        cout << '\n';
    }

    return (0 ^ 0);
}
