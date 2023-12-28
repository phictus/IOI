// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    string s;
    cin >> s;
    if (s[0] == '0')
    {
        cout << "-1\n";
        return;
    }

    int64_t index = 1, a = s[0] - '0', b = 0;
    while (index < s.size() && s[index] == '0')
    {
        a *= 10;
        a += s[index] - '0';
        index++;
    }

    while (index < s.size())
    {
        b *= 10;
        b += s[index] - '0';
        index++;
    }

    if (a < b)
        cout << a << ' ' << b << '\n';
    else
        cout << "-1\n";
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
