// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <limits>
#include <vector>
#include <cstdint>
#include <cmath>

using namespace std;

constexpr int64_t maxn = 300000, inf = numeric_limits<int64_t>::max();
bool a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t n;
    cin >> n;
    bool isAllOne = true;
    for (int64_t i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        a[i] = c == '1';
        if (!a[i])
            isAllOne = false;
    }

    if (isAllOne)
    {
        cout << "1\n";
        return 0;
    }

    int64_t l, r;
    for (int64_t i = 0; i < n; i++)
    {
        if (!a[i])
        {
            l = i;
            break;
        }
    }
    for (int64_t i = n - 1; i >= 0; i--)
    {
        if (!a[i])
        {
            r = i;
            break;
        }
    }

    int64_t nights = inf;
    if (l != 0)
        nights = min(nights, l - 1);
    if (r != n - 1)
        nights = min(nights, n - r - 2);

    int64_t last = l;
    while (!a[last])
        last++;

    vector<int64_t> list;
    for (int64_t i = last; i <= r; i++)
    {
        if (a[i])
            continue;

        list.push_back(i - last);
        while (i + 1 < n && !a[i + 1])
            i++;
        last = i + 1;
    }

    for (int64_t e : list)
        nights = min(nights, (e - 1) / 2);

    uint64_t result = 0;
    for (int64_t e : list)
        result += ceil(e / (double)(2 * nights + 1));

    result += ceil(l / (double)(2 * nights + 1));
    result += ceil((n - r - 1) / (double)(2 * nights + 1));
    cout << result << '\n';

    return (0 ^ 0);
}
