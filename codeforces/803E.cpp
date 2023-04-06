// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string str;
int32_t n, k;
bool loseState = false;

void printResults(bool condition, unordered_map<int32_t, int32_t>* up)
{
    if (!condition)
        cout << "NO" << endl;
    else
    {
        int32_t x = loseState ? -k : k;

        for (uint32_t i = n; i >= 1; i--)
        {
            if (x - up[i][x] == -1)
                str[i] = 'L';
            else if (x - up[i][x] == 1)
                str[i] = 'W';
            else
                str[i] = 'D';

            x = up[i][x];
        }

        cout << str.erase(0, 1) << endl;
    }
}

int main()
{
    cin >> n >> k;
    cin >> str;
    str = " " + str;

    unordered_map<int32_t, bool> dp[n + 1];
    unordered_map<int32_t, int32_t> up[n + 1];
    dp[0][0] = true;
    for (uint32_t i = 1; i <= n; i++)
    {
        const int32_t x = i == n ? 0 : 1;

        for (int32_t j = -k + x; j <= k - x; j++)
        {
            const bool w = j - 1 <= -k ? false : dp[i - 1][j - 1];
            const bool l = j + 1 >= k ? false : dp[i - 1][j + 1];
            const bool d = dp[i - 1][j];

            switch (str[i])
            {
            case 'W':
                dp[i][j] = w;
                up[i][j] = j - 1;
                break;

            case 'L':
                dp[i][j] = l;
                up[i][j] = j + 1;
                break;

            case 'D':
                dp[i][j] = d;
                up[i][j] = j;
                break;

            default:
                dp[i][j] = w + l + d;
                if (w)
                    up[i][j] = j - 1;
                else if (l)
                    up[i][j] = j + 1;
                else if (d)
                    up[i][j] = j;

                break;
            }
        }
    }

    switch(str[n])
    {
    case 'W':
        printResults(dp[n][k], up);
        break;

    case 'L':
        loseState = true;
        printResults(dp[n][-k], up);
        break;

    case 'D':
        printResults(false, up);
        break;

    default:
        if (dp[n][-k])
        {
            loseState = true;
            printResults(true, up);
        }
        else
            printResults(dp[n][k], up);
        break;
    }

    return (0 ^ 0);
}
