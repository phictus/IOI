// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>
#include <cstring>

using namespace std;

constexpr int64_t maxn = 101;
int64_t n, result;
string s;
char c[maxn];

int64_t GetMin(int64_t l, int64_t r)
{
    memset(c + l, '0', (r - l + 2) * sizeof(char));

    int64_t result = 0;
    for (int64_t i = l; i <= r; i++)
    {
        if (s[i] == '0')
            continue;

        if (c[i] != '1' && (i == 0 || c[i - 1] != '1'))
        {
            c[i + 1] = '1';
            result++;
        }
    }

    return result;
}

void SolveTestCase()
{
    cin >> n;
    cin >> s;

    result = 0;
    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = i; j < n; j++)
            result += GetMin(i, j);
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
