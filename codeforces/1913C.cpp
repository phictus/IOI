// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 30;
int64_t cnt[maxn];

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t m;
    cin >> m;
    while (m--)
    {
        int64_t type, value;
        cin >> type >> value;
        if (type == 1)
            cnt[value]++;
        else
        {
            for (int64_t i = 29; i >= 0; i--)
                value -= min(value >> i, cnt[i]) << i;

            if (value == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return (0 ^ 0);
}
