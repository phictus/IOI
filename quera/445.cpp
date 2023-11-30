// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <set>
#include <cstdint>

using namespace std;

constexpr int64_t maxk = 1000000;
int64_t k, n, a[2 * maxk + 1], cnt[maxk + 2];
set<int64_t> mexList;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> k >> n;
    n %= k + 1;
    for (int64_t i = 0; i < k; i++)
    {
        cin >> a[i];
        if (a[i] <= k + 1)
            cnt[a[i]]++;
    }

    for (int64_t i = 1; i <= k + 1; i++)
    {
        if (cnt[i] == 0)
            mexList.insert(i);
    }

    for (int64_t i = k; i <= k + n; i++)
    {
        a[i] = *mexList.begin();
        mexList.erase(mexList.begin());
        cnt[a[i]]++;

        if (a[i - k] <= k + 1)
        {
            cnt[a[i - k]]--;
            if (cnt[a[i - k]] == 0)
                mexList.insert(a[i - k]);
        }
    }

    cout << a[k + n] << '\n';

    return (0 ^ 0);
}
