// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 200000;
int64_t n, a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int64_t i = 0; i < n; i++)
            cin >> a[i];

        int64_t minIndex = 0;
        for (int64_t i = 1; i < n; i++)
        {
            if (a[i] < a[minIndex])
                minIndex = i;
        }

        bool result = true;
        for (int64_t i = minIndex + 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
                result = false;
        }

        if (result)
            cout << minIndex << '\n';
        else
            cout << "-1\n";
    }

    return (0 ^ 0);
}
