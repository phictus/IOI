// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;

constexpr int64_t maxn = 100000;
int64_t n, k;
Pair monsters[maxn];
int64_t minPower[maxn];

void Init()
{
    sort(monsters, monsters + n);
    minPower[n - 1] = monsters[n - 1].second;
    for (int64_t i = n - 2; i >= 0; i--)
        minPower[i] = min(minPower[i + 1], monsters[i].second);
}

int main()
{
    int64_t t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int64_t i = 0; i < n; i++)
            cin >> monsters[i].first;
        for (int64_t i = 0; i < n; i++)
            cin >> monsters[i].second;

        Init();

        bool result = false;
        int64_t offset = 0;
        while (k > 0)
        {
            offset += k;
            auto it = upper_bound(monsters, monsters + n, make_pair(offset + 1, (int64_t)0));

            if (it == monsters + n)
            {
                result = true;
                break;
            }

            k -= minPower[it - monsters];
        }

        if (result)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return (0 ^ 0);
}
