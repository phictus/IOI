// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdint>
#include <cctype>

using namespace std;

void SolveTestCase()
{
    string s;
    cin >> s;

    vector<char> result;
    int64_t lowerCount = 0, upperCount = 0;
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        if (*it == 'b')
            lowerCount++;
        else if (*it == 'B')
            upperCount++;
        else
        {
            if (islower(*it))
            {
                if (lowerCount > 0)
                    lowerCount--;
                else
                    result.push_back(*it);
            }
            else
            {
                if (upperCount > 0)
                    upperCount--;
                else
                    result.push_back(*it);
            }
        }
    }

    reverse(result.begin(), result.end());
    result.push_back('\0');
    cout << result.data() << '\n';
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
