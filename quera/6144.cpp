// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t n;
    cin >> n;

    vector<int64_t> s;
    for (int64_t i = 0; i < n; i++)
    {
        int64_t l;
        cin >> l;
        vector<int64_t> v;
        for (int64_t j = 0; j < l; j++)
        {
            int64_t p;
            cin >> p;
            v.push_back(p);
        }

        int64_t minimum = *v.rbegin();
        for (auto it = v.rbegin() + 1; it != v.rend(); it++)
        {
            minimum = min(minimum, *it);
            *it = minimum;
        }

        for (int64_t e : v)
            s.push_back(e);
    }

    sort(s.begin(), s.end());
    s.push_back(-1);
    for (int64_t i = 0; i < s.size(); i++)
    {
        if (i >= s[i])
        {
            cout << i << '\n';
            break;
        }
    }

    return (0 ^ 0);
}
