// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 200000;
int64_t n, a[maxn];

void SolveTestCase()
{
    cin >> n;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    int64_t result = 1, l = 0;
    set<int64_t> s;
    for (int64_t r = 0; r < n; r++)
    {
        s.insert(a[r]);
        while (a[r] - a[l] >= n)
        {
            s.erase(a[l]);
            l++;
        }

        result = max(result, (int64_t)s.size());
    }

    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t testCase;
    cin >> testCase;
    while (testCase--)
        SolveTestCase();

    return (0 ^ 0);
}
