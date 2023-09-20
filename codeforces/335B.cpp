// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
using HashMap = unordered_map<char, int32_t>;

constexpr int32_t maxLength = 26 * 99;
string str;
int32_t dp[maxLength][maxLength], length = 0;
char result[maxLength];

int32_t Init(int32_t l, int32_t r)
{
    if (l > r)
        return dp[l][r] = 0;
    else if (l == r)
        return dp[l][r] = 1;

    if (dp[l][r] > 0)
        return dp[l][r];

    if (str[l] == str[r])
        return dp[l][r] = Init(l + 1, r - 1) + 2;
    else
        return dp[l][r] = max(Init(l + 1, r), Init(l, r - 1));
}

void GetResult(int32_t l, int32_t r)
{
    if (l > r)
        return;
    else if (l == r)
        result[length++] = str[l];
    else if (str[l] == str[r])
    {
        result[length++] = str[l];
        GetResult(l + 1, r - 1);
        result[length++] = str[r];
    }
    else if (dp[l + 1][r] > dp[l][r - 1])
        GetResult(l + 1, r);
    else
        GetResult(l, r - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> str;
    if (str.size() > 26 * 99)
    {
        HashMap occurrence;
        for (char c : str)
        {
            occurrence[c]++;
            if (occurrence[c] == 100)
            {
                for (int32_t i = 0; i < 100; i++)
                    cout << c;
                cout << '\n';

                return (0 ^ 0);
            }
        }
    }

    for (int32_t i = 0; i < maxLength; i++)
    {
        for (int32_t j = i + 1; j < maxLength; j++)
            dp[i][j] = 0;
    }

    Init(0, str.size() - 1);
    GetResult(0, str.size() - 1);

    if (length <= 100)
    {
        for (int32_t i = 0; i < length; i++)
            cout << result[i];
        cout << '\n';
    }
    else
    {
        for (int32_t i = 0; i < 50; i++)
            cout << result[i];
        for (int32_t i = length - 50; i < length; i++)
            cout << result[i];
        cout << '\n';
    }

    return (0 ^ 0);
}
