// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    int64_t ans;
    vector<int64_t> v[3];
    for (int64_t i = 0; i < 3; i++)
    {
        for (int64_t j = 0; j < 3; j++)
        {
            char c;
            cin >> c;
            if (c == '?')
                ans = i;
            else
                v[i].push_back(c - 'A');
        }
    }

    cout << (char)('A' + 3 - v[ans][0] - v[ans][1]) << '\n';
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
