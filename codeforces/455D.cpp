// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <deque>
#include <cstdint>
#include <cmath>

using namespace std;

constexpr int64_t maxn = 100000, maxsqrtn = 317;
int64_t n, k, q;

deque<int64_t> a[maxsqrtn];
int64_t b[maxsqrtn][maxn + 1];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    k = ceil(sqrt(n));
    for (int64_t i = 0; i < n; i++)
    {
        int64_t x;
        cin >> x;
        a[i / k].push_back(x);
        b[i / k][x]++;
    }

    int64_t last = 0;
    cin >> q;
    while (q--)
    {
        int64_t type;
        cin >> type;
        if (type == 1)
        {
            int64_t l, r;
            cin >> l >> r;
            l = (l + last - 1) % n;
            r = (r + last - 1) % n;
            if (l > r)
                swap(l, r);

            if (l / k == r / k)
            {
                a[l / k].insert(a[l / k].begin() + l % k, a[l / k][r % k]);
                a[l / k].erase(a[l / k].begin() + r % k + 1);
            }
            else
            {
                a[r / k].push_front(a[r / k - 1].back());
                b[r / k][a[r / k].front()]++;

                for (int64_t i = r / k - 1; i > l / k; i--)
                {
                    b[i][a[i].back()]--;
                    a[i].pop_back();
                    a[i].push_front(a[i - 1].back());
                    b[i][a[i].front()]++;
                }

                a[l / k].insert(a[l / k].begin() + l % k, a[r / k][r % k + 1]);
                b[l / k][a[l / k][l % k]]++;

                b[r / k][a[r / k][r % k + 1]]--;
                a[r / k].erase(a[r / k].begin() + r % k + 1);

                b[l / k][a[l / k].back()]--;
                a[l / k].pop_back();
            }
        }
        else
        {
            int64_t l, r, v;
            cin >> l >> r >> v;
            l = (l + last - 1) % n;
            r = (r + last - 1) % n;
            v = (v + last - 1) % n + 1;
            if (l > r)
                swap(l, r);

            int64_t result = 0;
            if (l / k == r / k)
            {
                for (int64_t i = l % k; i <= r % k; i++)
                    result += a[l / k][i % k] == v;
            }
            else
            {
                for (int64_t i = l % k; i < a[l / k].size(); i++)
                    result += a[l / k][i] == v;
                for (int64_t i = 0; i <= r % k; i++)
                    result += a[r / k][i] == v;
                for (int64_t i = (l / k) + 1; i < r / k; i++)
                    result += b[i][v];
            }

            cout << result << '\n';
            last = result;
        }
    }

    return (0 ^ 0);
}
