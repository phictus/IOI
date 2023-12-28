// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

constexpr bool isVowel[5] = {true, false, false, false, true};
void SolveTestCase()
{
    int64_t n;
    string s;
    cin >> n >> s;

    vector<char> result;
    for (int64_t i = n - 1; i >= 0;)
    {
        result.push_back(s[i]);
        result.push_back(s[i - 1]);

        if (isVowel[s[i] - 'a'])
            i -= 2;
        else
        {
            result.push_back(s[i - 2]);
            i -= 3;
        }

        result.push_back('.');
    }

    for (auto it = result.rbegin() + 1; it != result.rend(); it++)
        cout << *it;
    cout << '\n';
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
