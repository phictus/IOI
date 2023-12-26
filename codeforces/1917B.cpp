// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <set>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    int64_t n, result = 0;
    set<char> s;

    cin >> n;
    for (int64_t i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        s.insert(c);
        result += s.size();
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
