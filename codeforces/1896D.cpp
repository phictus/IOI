// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <set>
#include <cstdint>

using namespace std;
constexpr int64_t maxn = 100000;
int64_t n, q, a[maxn], sum;
set<int64_t> oneList;

void Solve()
{
    cin >> n >> q;

    sum = 0;
    oneList.clear();
    for (int64_t i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (a[i] == 1)
            oneList.insert(i);
    }

    while (q--)
    {
        int64_t type;
        cin >> type;
        if (type == 1)
        {
            int64_t value;
            cin >> value;

            if (sum % 2 == value % 2)
            {
                if (sum < value)
                    cout << "NO\n";
                else
                    cout << "YES\n";
            }
            else
            {
                if (oneList.size() == 0)
                    cout << "NO\n";
                else
                {
                    int64_t x = 2 * *oneList.begin() + 1;
                    int64_t y = 2 * (n - *oneList.rbegin() - 1) + 1;
                    int64_t z = sum - min(x, y);

                    if (z < value)
                        cout << "NO\n";
                    else
                        cout << "YES\n";
                }
            }
        }
        else
        {
            int64_t index, value;
            cin >> index >> value;
            index--;

            sum += value - a[index];
            if (a[index] == 1)
            {
                if (value == 2)
                    oneList.erase(index);
            }
            else
            {
                if (value == 1)
                    oneList.insert(index);
            }

            a[index] = value;
        }
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
