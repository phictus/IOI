// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100000;
int64_t n, m, a[maxn], proficient[maxn + 1];
vector<int64_t> factors[maxn + 1];

void InitFactors()
{
    for (int64_t i = 1; i <= maxn; i++)
    {
        for (int64_t j = i; j <= maxn; j += i)
            factors[j].push_back(i);
    }
}

int64_t SolveTestCase()
{
    cin >> n >> m;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    for (int64_t i = 0; i <= m; i++)
        proficient[i] = 0;

    int64_t result = numeric_limits<int64_t>::max(), count = 0, j = -1;
    for (int64_t i = 0; i < n; i++)
    {
        while (count < m && j < n - 1)
        {
            j++;
            for (int64_t factor : factors[a[j]])
            {
                if (factor > m)
                    break;

                if (proficient[factor] == 0)
                    count++;
                proficient[factor]++;
            }
        }
        if (j == n - 1 && count < m)
            break;

        result = min(result, a[j] - a[i]);
        for (int64_t factor : factors[a[i]])
        {
            if (factor > m)
                break;

            proficient[factor]--;
            if (proficient[factor] == 0)
                count--;
        }
    }

    return result == numeric_limits<int64_t>::max() ? -1 : result;
}

int main()
{
    ios_base::sync_with_stdio(false);

    InitFactors();

    int64_t testCase;
    cin >> testCase;
    while (testCase--)
        cout << SolveTestCase() << '\n';

    return (0 ^ 0);
}
