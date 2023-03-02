// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int64_t n;
    cin >> n;
    pair<int64_t, int64_t> a[n];
    for (int64_t i = 0; i < n; i++)
    {
        a[i].second = i;
        cin >> a[i].first;
    }

    sort(a, a + n);
    pair<int64_t, int64_t> ans[n];
    int64_t x = 0;
    for (int64_t i = 0; i < n; i++)
    {
        ans[i].first = a[i].second;

        if (x < a[i].second)
        {
            ans[i].second = 0;
            x = a[i].second;
        }
        else
            ans[i].second = x - a[i].second;
    }

    sort(ans, ans + n);
    for (int64_t i = 0; i < n; i++)
        cout << ans[i].second - 1 << ' ';
    cout << endl;

    return (0 ^ 0);
}
